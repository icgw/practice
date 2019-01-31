/* Sort a linked list in O(nlog{n}) time using constant space complexity.
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
		static ListNode* sortList(ListNode* head){
			ListNode *slow = head, *fast = head;
			if (!head || !head->next) return head;
			while (fast->next && fast->next->next){
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode *second = slow->next;
			slow->next = NULL;
			ListNode *h = sortList(head); 
			ListNode *t = sortList(second);
			ListNode dummy(0);
			ListNode *curr = &dummy;
			while (h && t){
				if (h->val < t->val){
					curr->next = h;
					h = h->next;
				} else {
					curr->next = t;
					t = t->next;
				}
				curr = curr->next;
			}
			if (h) curr->next = h;
			if (t) curr->next = t;
			return dummy.next;
		}

		
};

int main(int argc, char *argv[]){
	ListNode *lst = new ListNode(-1);
	lst->next = new ListNode(5);
	lst->next->next = new ListNode(3);
	lst->next->next->next = new ListNode(4);
	lst->next->next->next->next = new ListNode(0);

	ListNode *ans = Solution::sortList(lst);
	while (ans){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;

	return 0;
}
