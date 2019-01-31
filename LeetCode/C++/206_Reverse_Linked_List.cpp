/* Reverse a single linked list.
 *
 * Example:
 *   Input: 1->2->3->4->5->NULL
 *  Output: 5->4->3->2->1->NULL
 *
 * Follow up:
 *  A linked list can be reversed either iteratively or recursively. 
 *  Could you implement both?
 */
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		/* static ListNode* reverseList(ListNode* head){
			ListNode *tmp, *prev = NULL;
			while (head){
				tmp = head->next;
				head->next = prev;
				prev = head;
				head = tmp;
			} // Iteratively.
			return prev;
		}*/

		static ListNode* reverseList(ListNode* head){
			if (!head || !head->next) return head;
			ListNode *newHead = reverseList(head->next);
			head->next->next = head;
			head->next = NULL;
			return newHead;
		} // Recursively.
};

int main(int argc, char *argv[]){
	ListNode *lst = new ListNode(1);
	lst->next = new ListNode(2);
	lst->next->next = new ListNode(3);
	lst->next->next->next = new ListNode(4);
	lst->next->next->next->next = new ListNode(5);
	ListNode *rev = Solution::reverseList(lst);
	while (rev){
		cout << rev->val << endl;
		rev = rev->next;
	}
	return 0;
}
