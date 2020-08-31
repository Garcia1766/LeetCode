from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        set1 = set()
        for num in nums:
            if num in set1:
                return True
            else:
                set1.add(num)
        return False

def main():
    nums = [1,2, 3, 4]
    print(Solution().containsDuplicate(nums))

if __name__ == '__main__':
    main()