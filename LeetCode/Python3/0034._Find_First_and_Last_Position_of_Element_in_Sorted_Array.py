#!/usr/bin/env python3
class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lo, hi = 0, len(nums) - 1
        idx1 = self.lower_bound(nums, target)
        idx2 = self.lower_bound(nums, target + 1) - 1
        return [idx1, idx2] if idx1 < len(nums) and nums[idx1] == target else [-1, -1]
    
    def lower_bound(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            if nums[mid] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return lo

if __name__ == "__main__":
    nums = [5, 7, 7, 8, 8, 10]
    print(Solution().searchRange(nums, 8))
    print(Solution().searchRange(nums, 6))
