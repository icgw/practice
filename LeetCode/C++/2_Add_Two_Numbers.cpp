/* You are given two non-empty linked lists representing two non-negative Inte-
 * gers. The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the 
 * number 0 itself.
 *
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
			ListNode* l1Ptr = l1;
			ListNode* l2Ptr = l2;

			ListNode *ans = new ListNode(0);
			ListNode *ptr = ans;

			int e, x, p;
			p = 0;
			bool flag;
			while (l1Ptr != NULL && l2Ptr != NULL){
				e = l1Ptr->val + l2Ptr->val;
				x = e + p;
				if (x > 9){
					x = x % 10;
					p = 1;
				} else {
					p = 0;
				}

				ptr->val = x;
				flag = true;
				if ((l1Ptr->next != NULL && l2Ptr->next != NULL) || p == 1){
					ptr->next = new ListNode(p);
				    ptr = ptr->next;
					flag = false;
				}

				l1Ptr = l1Ptr->next;
				l2Ptr = l2Ptr->next;
			}
			
			while (l1Ptr != NULL){
				if (flag){
					ptr->next = l1Ptr;
					break;
				} 
				x = ptr->val + l1Ptr->val;
				if (x > 9){
					x = x % 10;
					p = 1;
				} else {
					p = 0;
				}
				ptr->val = x;
				if (p == 1){
					ptr->next = new ListNode(p);
					ptr = ptr->next;
				} else {
					ptr->next = l1Ptr->next;
					break;
				}
				l1Ptr = l1Ptr->next;
			}
			while (l2Ptr != NULL){
				if (flag){
					ptr->next = l2Ptr;
					break;
				}
				x = ptr->val + l2Ptr->val;
				if (x > 9){
					x = x % 10;
					p = 1;
				} else {
					p = 0;
				}
				ptr->val = x;
				if (p == 1){
					ptr->next = new ListNode(p);
					ptr = ptr->next;
				} else {
					ptr->next = l2Ptr->next;
					break;
				}
				l2Ptr = l2Ptr->next;
			}
			return ans;
		}
};

int main(int argc, char *args[]){
	ListNode l1(9);

	ListNode l2(1);
	l2.next = new ListNode(9);
	l2.next->next = new ListNode(9);
	l2.next->next->next = new ListNode(8);
	l2.next->next->next->next = new ListNode(9);

	Solution st;
	ListNode *ans = st.addTwoNumbers(&l1, &l2);

	ListNode *p = ans;
	while (p != NULL){
		printf("%d", p->val);
		p = p->next;
		if (p != NULL){
			printf("->");
		}
	}
	printf("\n");

	return 0;
}
