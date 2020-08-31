from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        set1 = set()
        l, r = 0, k  # [l, r]
        for i in range(l, min(r + 1, len(nums))):
            if nums[i] in set1:
                return True
            else:
                set1.add(nums[i])
        for i in range(k + 1, len(nums)):
            set1.remove(nums[i - k - 1])
            if nums[i] in set1:
                return True
            else:
                set1.add(nums[i])
        return False

def main():
    nums = [1,2,3,1,2,3]
    k = 2
    print(Solution().containsNearbyDuplicate(nums, k))

if __name__ == '__main__':
    main()
