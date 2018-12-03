#!/usr/bin/env python3
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        candidates.sort()
        self.dfs(candidates, target, 0, [], res)
        return res

    def dfs(self, nums, tgt, idx, path, res):
        """
        :type nums: List[int]
        :type tgt: int
        :type idx: int
        :type path: List[int]
        :type res: List[List[int]]
        :rtype: void
        """
        if tgt < 0: return
        if tgt == 0: res.append(path); return
        for i in range(idx, len(nums)):
            self.dfs(nums, tgt - nums[i], i, path + [nums[i]], res)

if __name__ == "__main__":
    print(Solution().combinationSum([2, 3, 6, 7], 7))
    print(Solution().combinationSum([2, 3, 5], 8))
