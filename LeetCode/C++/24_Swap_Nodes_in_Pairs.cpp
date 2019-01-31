/* Given a linked list, swap every two adjacent nodes and return its head.
 *
 * Example:
 * 	Given 1->2->3->4, you shhould return the list as 2->1->4->3.
 *
 * Note:
 * 	+ Your algorithm should use only constant extra space.
 * 	+ You may not modify the values in the list's nodes, only nodes itself may
 * 	  be changed.
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
		static ListNode* swapPairs(ListNode* head) {
			ListNode* ans, * pA, * pB, * pt;
			if (head == NULL || head->next == NULL){
				return head;
			}

			ans = head->next;

			pA = head;
			pt = pA;
			pB = head->next;
			while (pA != NULL && pB != NULL){
				pt->next = pB;
				pt = pA;
				pA->next = pB->next;
				pB->next = pA;

				pA = pA->next;
				if (pA == NULL)
					break;
				pB = pA->next;
			}
			return ans;
		}
};

int main(int argc, char* agrs[]) {
	ListNode* a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(3);
	a->next->next->next = new ListNode(4);

	ListNode* ans = Solution::swapPairs(a);
	ListNode* p_ans = ans;
	while (p_ans != NULL){
		if (p_ans->next != NULL){
			cout << p_ans->val << "->";
		} else {
			cout << p_ans->val;
		}
		p_ans = p_ans->next;
	}
	cout << endl;



	return 0;
}
