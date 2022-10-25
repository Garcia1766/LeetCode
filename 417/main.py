from collections import deque
from typing import List, Deque, Tuple

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
        n_rows, n_cols = len(heights), len(heights[0])
        pacific_queue = deque()
        atlantic_queue = deque()
        for i in range(n_rows):
            pacific_queue.append((i, 0))
            atlantic_queue.append((i, n_cols - 1))
        for j in range(n_cols):
            pacific_queue.append((0, j))
            atlantic_queue.append((n_rows - 1, j))

        def bfs(queue: Deque[Tuple[int, int]]):
            reachable = set()
            while queue:
                (x, y) = queue.popleft()
                reachable.add((x, y))
                for cor in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                    nx, ny = x + cor[0], y + cor[1]
                    # in board?
                    if nx < 0 or nx >= n_rows or ny < 0 or ny >= n_cols:
                        continue
                    # visited?
                    if (nx, ny) in reachable:
                        continue
                    # heights satisfy?
                    if heights[nx][ny] < heights[x][y]:
                        continue
                    queue.append((nx, ny))
            return reachable
        
        p_res = bfs(pacific_queue)
        a_res = bfs(atlantic_queue)
        return list(p_res.intersection(a_res))

