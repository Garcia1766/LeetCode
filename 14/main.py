from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        shortest = min(strs, key=len)
        for i, ch in enumerate(shortest):
            for other in strs:
                if other[i] != ch:
                    return shortest[:i]
        return shortest 
        

if __name__ == "__main__":
    strs = ["flower","flow","flight"]
    res = Solution().longestCommonPrefix(strs)
    print(res)
