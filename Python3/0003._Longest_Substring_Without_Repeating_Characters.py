#!/usr/bin/env python3
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        w = ""
        count = maxLen = 0
        for ch in s:
            if ch not in w:
                w += ch
                count += 1
            else:
                if count > maxLen:
                    maxLen = count
                index = w.find(ch)
                w = w[index + 1:] + ch
                count = count - index
        return max(count, maxLen)

if __name__ == "__main__":
    s1 = "abcabcbb"
    print(Solution().lengthOfLongestSubstring(s1))
    s2 = "bbbbb"
    print(Solution().lengthOfLongestSubstring(s2))
    s3 = "pwwkew"
    print(Solution().lengthOfLongestSubstring(s3))
