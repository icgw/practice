#!/usr/bin/env python3
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        charMatch = lambda x, y : x == y or y == '.'
        m, n = len(s), len(p)
        dp = [[False for _ in range(n + 1)] for _ in range(m + 1)]
        dp[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i][j - 2] or (i > 0 and charMatch(s[i - 1], p[j - 2]) and dp[i - 1][j]) if p[j - 1] == '*' else i > 0 and charMatch(s[i - 1], p[j - 1]) and dp[i - 1][j - 1]
        return dp[m][n]

if __name__ == "__main__":
    s = "aa"
    p = "a"
    print(Solution().isMatch(s, p))
    s = "aa"
    p = "a*"
    print(Solution().isMatch(s, p))
    s = "ab"
    p = ".*"
    print(Solution().isMatch(s, p))
    s = "aab"
    p = "c*a*b"
    print(Solution().isMatch(s, p))
    s = "mississippi"
    p = "mis*is*p*."
    print(Solution().isMatch(s, p))
