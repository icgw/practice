#!/usr/bin/env python3
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n, rList = len(nums), []
        for i in range(n - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            lo, hi, tgt = i + 1, n - 1, -nums[i]
            while lo < hi:
                s = nums[lo] + nums[hi]
                if s == tgt:
                    rList.append([nums[i], nums[lo], nums[hi]])
                    lo += 1; hi -= 1
                    while lo < hi and nums[lo] == nums[lo - 1]:
                        lo += 1
                    while hi > lo and nums[hi] == nums[hi + 1]:
                        hi -= 1
                elif s < tgt:
                    lo += 1
                else:
                    hi -= 1
        return rList

if __name__ == "__main__":
    nums = [-1, 0, 1, 2, -1, -4]
    print(Solution().threeSum(nums))
