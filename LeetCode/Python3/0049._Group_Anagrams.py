#!/usr/bin/env python3
class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = {}
        for w in sorted(strs):
            k = tuple(sorted(w))
            d[k] = d.get(k, []) + [w]
        return list(d.values())

if __name__ == "__main__":
    print(Solution().groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))

