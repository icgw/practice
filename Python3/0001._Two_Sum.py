#!/usr/bin/env python3
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup = {}
        for i, num in enumerate(nums):
            if num in lookup:
                return [lookup[num], i]
            lookup[target - num] = i

if __name__ == "__main__":
    print(Solution().twoSum([2, 7, 11, 15], 9))
