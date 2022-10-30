

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp_grid = [[0 for j in range(len(text2) + 1)] for i in range(len(text1) + 1)]
        for i in reversed(range(len(text1))):
            for j in reversed(range(len(text2))):
                if text1[i] == text2[j]:
                    dp_grid[i][j] = 1 + dp_grid[i + 1][j + 1]
                else:
                    dp_grid[i][j] = max(dp_grid[i + 1][j], dp_grid[i][j + 1])
        return dp_grid[0][0]


if __name__ == "__main__":
    text1 = "abcde"
    text2 = "ace" 
    res = Solution().longestCommonSubsequence(text1, text2)
    print(res)
