#!/usr/bin/env python3
from dataStructures import ListNode

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = p = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        p.next = l1 or l2
        return dummy.next

if __name__ == "__main__":
    l1 = ListNode.stringToListNode("[1, 2, 4]")
    l2 = ListNode.stringToListNode("[1, 3, 4]")
    print(Solution().mergeTwoLists(l1, l2))
