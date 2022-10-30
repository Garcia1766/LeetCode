from functools import lru_cache

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> str:
        @lru_cache(maxsize=None)
        def solve(p1: int, p2: int) -> str:
            if p1 == len(text1) or p2 == len(text2):
                return ""
            
            if text1[p1] == text2[p2]:
                return text1[p1] + solve(p1 + 1, p2 + 1)
            else:
                return max(solve(p1 + 1, p2), solve(p1, p2 + 1), key=len)
        return solve(0, 0)


if __name__ == "__main__":
    text1 = "abcde"
    text2 = "ace" 
    res = Solution().longestCommonSubsequence(text1, text2)
    print(res)
