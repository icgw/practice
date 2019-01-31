/* Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * 	Input: 1->2->4, 1->3->4
 * 	Output: 1->1->2->3->4->4
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
		static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (l1 == NULL)
				return l2;
			if (l2 == NULL)
				return l1;

			ListNode *ptr1 = l1, *ptr2 = l2;
			ListNode *ans = new ListNode(0);
			ListNode *p_ans = ans;
			while (ptr1 != NULL || ptr2 != NULL){
				if (ptr1 == NULL){
					while (ptr2 != NULL){
						p_ans->val = ptr2->val;
						if (ptr2->next != NULL){
							p_ans->next = new ListNode(0);
						} else {
							break;
						}
						p_ans = p_ans->next;
						ptr2 = ptr2->next;
					}
					break;
				}
				if (ptr2 == NULL){
					while (ptr1 != NULL){
						p_ans->val = ptr1->val;
						if (ptr1->next != NULL){
							p_ans->next = new ListNode(0);
						} else {
							break;
						}
						p_ans = p_ans->next;
						ptr1 = ptr1->next;
					}
					break;
				}
				if (ptr1->val < ptr2->val) {
					p_ans->val = ptr1->val;
					p_ans->next = new ListNode(0);
					p_ans = p_ans->next;
					ptr1 = ptr1->next;
				} else {
					p_ans->val = ptr2->val;
					p_ans->next = new ListNode(0);
					p_ans = p_ans->next;
					ptr2 = ptr2->next;
				}
			}
			return ans;
		}
};

int main(int argc, char *args[]) {
	ListNode a(1);
	a.next = new ListNode(2);
	a.next->next = new ListNode(4);

	ListNode b(1);
	b.next = new ListNode(3);
	b.next->next = new ListNode(4);

	ListNode* c = Solution::mergeTwoLists(&a, &b);
	ListNode* ptr_c = c;
	while (ptr_c != NULL){
		if (ptr_c->next != NULL){
			cout << ptr_c->val << "->";
		} else {
			cout << ptr_c->val;
		}
		ptr_c = ptr_c->next;
	}
	cout << endl;

	return 0;
}
