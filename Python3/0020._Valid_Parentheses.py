#!/usr/bin/env python3
class Solution:
    m = {')': '(', ']': '[', '}': '{'}

    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = []
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                stk.append(ch)
            else:
                if stk and stk[-1] == self.m[ch]:
                    stk.pop()
                else:
                    return False
        return not stk

if __name__ == "__main__":
    s = "()"
    print(Solution().isValid(s))
    s = "()[]{}"
    print(Solution().isValid(s))
    s = "(]"
    print(Solution().isValid(s))
    s = "([)]"
    print(Solution().isValid(s))
    s = "{[]}"
    print(Solution().isValid(s))
