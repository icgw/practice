/* Given a sorted linked list, delete all duplicates such that each element 
 * appear only once.
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
		static ListNode* deleteDuplicates(ListNode* head){
			if (head == NULL || head->next == NULL) return head;
			ListNode* ptr = head;
			ListNode* curr = ptr;
			while (ptr->next){
				curr = ptr->next;
				while (curr && curr->val == ptr->val) curr = curr->next;
				if (curr == ptr->next)
					ptr = ptr->next;
				else
					ptr->next = curr;
			}
			return head;
		}
};

int main(int argc, char* args[]){
	ListNode* ls1 = new ListNode(1);
	ls1->next = new ListNode(1);
	ls1->next->next = new ListNode(2);

	ListNode* ans1 = Solution::deleteDuplicates(ls1);
	ListNode* ptr = ans1;
	while (ptr->next){
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout << ptr->val << endl;

	return 0;
}
