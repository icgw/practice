#!/usr/bin/env python3
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        longestPLDR = ""
        for i, ch in enumerate(s):
            odd  = self.growPalindrome(s, i, i)
            even = self.growPalindrome(s, i, i + 1)
            win  = odd if len(odd) > len(even) else even
            if len(win) > len(longestPLDR):
                longestPLDR = win
        return longestPLDR

    def growPalindrome(self, s, l, r):
        """
        :type s: str
        :type l: int
        :type r: int
        :rtype: str
        """
        n = len(s)
        while l >= 0 and r < n and s[l] == s[r]:
            l -= 1; r += 1
        return s[l + 1 : r]

if __name__ == "__main__":
    s = "babad"
    print(Solution().longestPalindrome(s))
    s = "cbbd"
    print(Solution().longestPalindrome(s))
