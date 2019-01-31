/* Given a linked list, return the node where the cycle begins. If there is no 
 * cycle, return `null'.
 *
 * Note: Do not modify the linked list.
 *
 * Follow up:
 * 	Can you solve it without using extra space?
 */ 
#include <iostream>

struct List {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		static ListNode *detectCycle(ListNode *head){
			ListNode *fast = head, *slow = head;
			while (fast && fast->next){
				fast = fast->next->next;
				slow = slow->next;
				if (fast == slow) break;
			}
			if (!fast || !fast->next) return NULL;
			slow = head;
			while (slow != fast) slow = slow->next, fast = fast->next;
			return fast;
		}
};
