/* Given a linked list, remove the n-th node from the end of list and return its
 * head.
 *
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 
 * 1->2->3->5.
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
		static ListNode* removeNthFromEnd(ListNode* head, int n) {
			int len = 0, m;
			ListNode* ptr = head;
			while (ptr != NULL){
				ptr = ptr->next;
				++len;
			}
			if (len == 1 && n == 1){
				return NULL;
			}
			if (len == n){
				return head->next;
			}

			m = len - n;
			int i = 0;
			ptr = head;
			ListNode* ptr_n;
			while (i < m - 1){
				ptr = ptr->next;
				++i;
			}
			ptr_n = ptr->next;
			ptr->next = ptr_n->next;
			delete ptr_n;

			return head;
		}
};

int main(int argc, char *args[]) {
	ListNode a(1);
	a.next = new ListNode(2);
	a.next->next = new ListNode(3);
	a.next->next->next = new ListNode(4);
	a.next->next->next->next = new ListNode(5);

	ListNode b(1);

	ListNode* ptr = Solution::removeNthFromEnd(&a, 2);
	while (ptr != NULL){
		if (ptr->next != NULL){
			cout << ptr->val << "->";
		} else {
			cout << ptr->val;
		}
		ptr = ptr->next;
	}
	cout << endl;
	
	ptr = Solution::removeNthFromEnd(&b, 1);
	while (ptr != NULL){
		if (ptr->next != NULL){
			cout << ptr->val << "->";
		} else {
			cout << ptr->val;
		}
		ptr = ptr->next;
	}
	cout << endl;

	return 0;
}
