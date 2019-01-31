#!/usr/bin/env python3
from data_structures import ListNode

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        return self.doMerge(lists, 0, len(lists))

    def doMerge(self, lists, lo, hi):
        """
        :type lists: List[ListNode]
        :type lo: int
        :type hi: int
        :rtype: ListNode
        """
        if lo >= hi: return None
        if lo + 1 == hi: return lists[lo]
        if lo + 2 == hi: return self.mergeTwoLists(lists[lo], lists[lo + 1])
        m = (lo + hi) // 2
        l1 = self.doMerge(lists, lo, m)
        l2 = self.doMerge(lists, m, hi)
        return self.mergeTwoLists(l1, l2)

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
    l1 = ListNode.stringToListNode("[1, 4, 5]")
    l2 = ListNode.stringToListNode("[1, 3, 4]")
    l3 = ListNode.stringToListNode("[2, 6]")
    print(Solution().mergeKLists([l1, l2, l3]))
