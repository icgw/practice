package _0002_add_two_numbers;

import structure.ListNode;

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2){
        ListNode dummyRoot = new ListNode(0);
        ListNode ptr = dummyRoot;
        int sum = 0;
        while (l1 != null || l2 != null || sum >= 10){
            sum /= 10;
            if (l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null){
                sum += l2.val;
                l2 = l2.next;
            }
            ptr.next = new ListNode(sum % 10);
            ptr = ptr.next;
        }
        return dummyRoot.next;
    }

    public static void main(String[] args){
        Solution s = new Solution();
        ListNode.prettyPrintLinkedList(s.addTwoNumbers(
                ListNode.stringToListNode("[2, 4, 3]"),
                ListNode.stringToListNode("[5, 6, 4]")));
    }
}
