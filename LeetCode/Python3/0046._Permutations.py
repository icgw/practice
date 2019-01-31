#!/usr/bin/env python3
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        added, res = [False for _ in range(len(nums))], []
        self.dfs(res, [], nums, added)
        return res

    def dfs(self, res, path, nums, added):
        """
        :type res: List[List[int]]
        :type path: List[int]
        :type nums: List[int]
        :type added: List[bool]
        :rtype: void
        """
        if len(path) == len(nums):
            res.append(path)
            return 

        for i in range(len(nums)):
            if not added[i]:
                added[i] = True
                self.dfs(res, path + [nums[i]], nums, added)
                added[i] = False

if __name__ == "__main__":
    print(Solution().permute([1, 2, 3]))
