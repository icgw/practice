#!/usr/bin/env python3
from data_structures import ListNode

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p, count = head, 0
        for _ in range(n):
            p = p.next
        
        if p is None:
            return head.next

        curr = head
        while p.next:
            curr, p = curr.next, p.next
        curr.next = curr.next.next
        return head

if __name__ == "__main__":
    lst = ListNode.stringToListNode("[1, 2, 3, 4, 5]")
    print(Solution().removeNthFromEnd(lst, 2))
