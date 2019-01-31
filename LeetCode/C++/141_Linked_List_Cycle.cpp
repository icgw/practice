/* Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */ 
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		/* static bool hasCycle(ListNode *head){ // This idea is not good.
			ListNode *terminate = new ListNode(0), *tmp;
			while (head && head->next != terminate){
				tmp = head->next;
				head->next = terminate;
				head = tmp;
			}
			return (head != NULL);
		} */
		bool hasCycle(ListNode *head){
			ListNode *fast = head, *slow = head;
			while (fast && fast->next){
				slow = slow->next;
				fast = fast->next->next;
				if (slow == fast) return true;
			}
			return false;
		}
};
