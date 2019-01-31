#!/usr/bin/env python3
class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]: i -= 1
        if i < 0: 
            nums.reverse()
        else:
            j = len(nums) - 1
            while j > i and nums[j] <= nums[i]: j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            self.reverse(nums, i + 1)

    def reverse(self, nums, begin):
        """
        :type nums: List[int]
        :type begin: int
        :rtype: void
        """
        end = len(nums) - 1
        while begin < end:
            nums[begin], nums[end] = nums[end], nums[begin]
            begin += 1; end -= 1

if __name__ == "__main__":
    nums = [1, 2, 3]
    Solution().nextPermutation(nums); print(nums)
    nums = [3, 2, 1]
    Solution().nextPermutation(nums); print(nums)
    nums = [1, 1, 5]
    Solution().nextPermutation(nums); print(nums)
