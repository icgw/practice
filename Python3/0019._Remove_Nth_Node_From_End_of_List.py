#!/usr/bin/env python3
from dataStructures import ListNode

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
    lst = ListNode(1)
    lst.next = ListNode(2)
    lst.next.next = ListNode(3)
    lst.next.next.next = ListNode(4)
    lst.next.next.next.next = ListNode(5)
    ans = Solution().removeNthFromEnd(lst, 2)
    while ans:
        print(ans.val)
        ans = ans.next
