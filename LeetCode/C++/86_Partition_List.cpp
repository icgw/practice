/* Given a linked list and a value x, partition it such that all nodes less than
 * x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the 
 * two partitions.
 *
 * Example:
 * 	Input: head = 1->4->3->2->5->2, x = 3
 * 	Output: 1->2->2->4->3->5
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
		static ListNode* partition(ListNode* head, int x){
			if (head == NULL) return head;
			if (head->next == NULL) return head;
			ListNode* dummy = new ListNode(0);
			ListNode* ptr = dummy;
			ptr->next = head;
			ListNode* curr;
			while (ptr->next){
				curr = ptr->next;
				if (curr->val >= x) break;
				ptr = ptr->next;
			}

			ListNode* curr2;
			while (curr && curr->next){
				curr2 = curr->next;
				if (curr2->val < x){
					curr->next = curr2->next;
					curr2->next = ptr->next;
					ptr->next = curr2;
					ptr = ptr->next;
				} else {
					curr = curr->next;
				}
			}
			return dummy->next;
		}

};

int main(int argc, char* args[]){
	ListNode *ls1 = new ListNode(1);
	ls1->next = new ListNode(4);
	ls1->next->next = new ListNode(3);
	ls1->next->next->next = new ListNode(2);
	ls1->next->next->next->next = new ListNode(5);
	ls1->next->next->next->next->next = new ListNode(2);
	int x = 3;

	Solution::partition(ls1, x);
	ListNode *ptr = ls1;
	while (ptr->next){
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout << ptr->val << endl;

	return 0;
}
