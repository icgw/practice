/* Given a singly linked list L: L0->L1->...->L{n-1}->Ln,
 * reorder it to: L0->Ln->L1->L{n-1}->L2->L{n-2}->...
 *
 * You may not modify the values in the list's nodes, 
 * only nodes itself may be changed.
 *
 * Example:
 * 	Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
		static void reorderList(ListNode* head){
			if (head || head->next) return ;
			ListNode *slow = head, *fast = head;
			while (fast && fast->next){
				slow = slow->next;
				fast = fast->next->next;
			}

			ListNode *t = NULL, *tmp, *p = slow;
			while (p){
				tmp = p->next;
				p->next = t;
				t = p;
				p = tmp;
			}
			while (t){
				tmp = head->next, head->next = t, head = tmp;
				if (head == slow) break;
				tmp = t->next, t->next = head, t = tmp;
			}
		}
};

int main(int argc, char *argv[]){
	ListNode *lst = new ListNode(1);
	lst->next = new ListNode(2);
	lst->next->next = new ListNode(3);
	lst->next->next->next = new ListNode(4);
	lst->next->next->next->next = new ListNode(5);

	Solution::reorderList(lst);
	while (lst){
		cout << lst->val << " ";
		lst = lst->next;
	}
	cout << endl;
	return 0;
}
