#!/usr/bin/env python3
class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            if nums[mid] == target: return mid
            if (nums[0] > nums[mid]) ^ (nums[0] > target) ^ (target > nums[mid]):
                lo = mid + 1
            else:
                hi = mid - 1
        return -1

    def search_pre2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        lo, hi = 0, len(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            num = nums[mid] if (nums[mid] < nums[0]) == (target < nums[0]) \
                    else float('-inf') if target < nums[0] else float('inf')
            if num == target: return mid
            if num < target:
                lo = mid + 1
            else:
                hi = mid
        return -1

    def search_pre1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        lo, hi = 0, n - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] < nums[hi]: hi = mid
            else: lo = mid + 1
        p = lo
        lo, hi = 0, n - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            real_mid = (mid + p) % n
            if nums[real_mid] == target: return real_mid
            if nums[real_mid] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return -1

if __name__ == "__main__":
    nums = [4, 5, 6, 7, 0, 1, 2]
    print(Solution().search(nums, 0))
    print(Solution().search(nums, 3))
