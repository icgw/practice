/* Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 <= m <= n <= length of list.
 * Example:
 * 	Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * 	Output: 1->4->3->2->5->NULL
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
		static ListNode* reverseBetween(ListNode* head, int m, int n){
			ListNode* pp = NULL, *pt, *prev, *back, *bb;
			int i = 1;
			if (head == NULL) return head;
			prev = head, back = head->next;
			while (i < m){
				pp = prev;
				prev = prev->next;
				back = back->next;
				++i;
			}

			pt = pt == head ? NULL : pp;
			ListNode* hh = prev;
			while (i < n){
				bb = back->next;
				back->next = prev;
				prev->next = pp;

				pp = prev;
				prev = back;
				back = bb;
				++i;
			}
			if (pt != NULL) pt->next = prev;
			hh->next = back;
			return pt == NULL ? prev : head;
		}
};

int main(int argc, char* args[]){
	ListNode* lst = new ListNode(1);
	lst->next = new ListNode(2);
	lst->next->next = new ListNode(3);
	lst->next->next->next = new ListNode(4);
	lst->next->next->next->next = new ListNode(5);

	int m = 2, n = 4;
	
	ListNode* ptr = Solution::reverseBetween(lst, m, n);
	while (ptr->next){
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout << ptr->val << endl;
	
	return 0;
}
