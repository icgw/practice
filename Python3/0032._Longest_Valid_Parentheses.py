#!/usr/bin/env python3
class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s); dp = [0 for _ in range(n)]
        curr_max = 0
        for i in range(1, n):
            l = i - dp[i - 1] - 1
            if s[i] == ')' and l >= 0 and s[l] == '(':
                dp[i] = dp[i - 1] + 2 + (dp[l - 1] if l - 1 >= 0 else 0)
                if dp[i] > curr_max: curr_max = dp[i]
        return curr_max

if __name__ == "__main__":
    print(Solution().longestValidParentheses("(()"))
    print(Solution().longestValidParentheses(")()())"))
