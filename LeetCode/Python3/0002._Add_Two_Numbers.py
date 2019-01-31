#!/usr/bin/env python3
from data_structures import ListNode

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        ptr, s = dummy, 0
        while l1 or l2 or s >= 10:
            s //= 10
            if l1:
                s += l1.val
                l1 = l1.next
            if l2:
                s += l2.val
                l2 = l2.next
            ptr.next = ListNode(s % 10)
            ptr = ptr.next
        return dummy.next

    def addTwoNumbers_pre(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        current, carry = dummy, 0
        while l1 or l2 or carry:
            val = carry;
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            carry = val // 10
            current.next = ListNode(val % 10)
            current = current.next
        return dummy.next

if __name__ == "__main__":
    a = ListNode.stringToListNode("[2, 4, 3]");
    b = ListNode.stringToListNode("[5, 6, 4]");
    print(Solution().addTwoNumbers(a, b))
