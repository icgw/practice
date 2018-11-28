#!/usr/bin/env python3
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        m, st, ans = {}, 0, 0
        for i, ch in enumerate(s):
            if ch not in m or m[ch] < st:
                ans = max(ans, i - st + 1)
            else:
                st = m[ch] + 1
            m[ch] = i
        return ans

    def lengthOfLongestSubstring_pre2(self, s):
        """
        :type s: str
        :rtype: int
        """
        m, i, ans = {}, 0, 0
        for j, ch in enumerate(s):
            i = max(m[ch], i) if ch in m else i
            ans = max(ans, j - i + 1)
            m[ch] = j + 1
        return ans

    def lengthOfLongestSubstring_pre1(self, s):
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
