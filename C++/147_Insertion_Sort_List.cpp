/* Sort a linked list using insertion sort.
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
		static ListNode* insertionSortList(ListNode* head){
			ListNode *dummy = new ListNode(0);
			ListNode *tmp, *ht;
			while (head){
				tmp = dummy;
				while (tmp->next && head->val > tmp->next->val) tmp = tmp->next;
				ht = head->next;
				head->next = tmp->next;
				tmp->next = head;
				head = ht;
			}
			return dummy->next;
		}
};

int main(int argc, char *argv[]){
	ListNode *lst = new ListNode(-1);
	lst->next = new ListNode(5);
	lst->next->next = new ListNode(3);
	lst->next->next->next = new ListNode(4);
	lst->next->next->next->next = new ListNode(0);

	ListNode* ans = Solution::insertionSortList(lst);
	while (ans){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;

	return 0;
}
