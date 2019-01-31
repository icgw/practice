import json
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        return "{} -> {}".format(self.val, self.next)

    @staticmethod
    def stringToListNode(list_str):
        """
        :type list_str: str, e.g., [x, y, ..]
        :rtype: ListNode
        """
        # Generate list from the input
        nums = json.loads(list_str)

        # Now convert that list into linked list
        dummyRoot = ListNode(0)
        ptr = dummyRoot
        for n in nums:
            ptr.next = ListNode(n)
            ptr = ptr.next
        return dummyRoot.next
