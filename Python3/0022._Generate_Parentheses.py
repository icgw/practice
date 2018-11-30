#!/usr/bin/env python3
class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ps = []
        self.dfs(ps, "", n, 0)
        return ps
    
    def dfs(self, prts, s, lbn, rbn):
        """
        :type prts: List[str]
        :type s: str
        :type lbn: int
        :type rbn: int
        """
        if lbn == 0 and rbn == 0: prts.append(s)
        if lbn > 0: self.dfs(prts, s + '(', lbn - 1, rbn + 1)
        if rbn > 0: self.dfs(prts, s + ')', lbn, rbn - 1)

if __name__ == "__main__":
    print(Solution().generateParenthesis(3))
