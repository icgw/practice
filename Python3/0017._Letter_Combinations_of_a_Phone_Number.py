#!/usr/bin/env python3
class Solution:
    d = {'2': "abc", '3': "def", \
            '4': "ghi", '5': "jkl", '6': "mno", \
            '7': "pqrs", '8': "tuv", '9': "wxyz"}
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        c = []
        self.dfs(c, "", digits)
        return c

    def dfs(self, cmbs, s, r):
        """
        :type cmbs: List[str]
        :type s: str
        :type r: str
        """
        if not r: return cmbs.append(s) if s else None
        for ch in self.d[r[0]]: 
             self.dfs(cmbs, s + ch, r[1:])

    def letterCombinations_pre1(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits: return []
        if len(digits) == 1: return [x for x in self.d[digits[0]]]
        return [x + y for x in self.d[digits[0]] for y in self.letterCombinations(digits[1:])]

if __name__ == "__main__":
    digits = "23"
    print(Solution().letterCombinations(digits))
