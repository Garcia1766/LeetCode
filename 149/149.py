import math

class Solution:
    def slope(self, p1: list, p2: list) -> (int, int):
        if p1[0] == p2[0]:
            return (0, 1)
        elif p1[1] == p2[1]:
            return (1, 0)
        else:
            dx, dy = p1[0] - p2[0], p1[1] - p2[1]
            if dx < 0:
                dx, dy = -dx, -dy
            gcd = math.gcd(dx, dy)
            return (dx / gcd, dy / gcd)
    
    def maxPoints(self, points: list) -> int:
        if len(points) < 1:
            return 0
        ans = 1
        for i in range(len(points) - 1):
            map1 = {}
            max_count_i, duplicate = 1, 0
            for j in range(i + 1, len(points)):
                if points[i][0] == points[j][0] and points[i][1] == points[j][1]:
                    duplicate += 1
                else:
                    slope = self.slope(points[i], points[j])
                    map1[slope] = map1.get(slope, 1) + 1
                    max_count_i = max(map1[slope], max_count_i)
            max_count_i += duplicate
            ans = max(ans, max_count_i)
        return ans
            
def main():
    points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    print(Solution().maxPoints(points))

if __name__ == '__main__':
    main()
