/* Given a linked list, rotate the list to the right by k places, where k is 
 * non-nagative.
 *
 * Example 1:
 * 	Input: 1->2->3->4->5->NULL, k = 2
 * 	Output: 4->5->1->2->3->NULL
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
		static ListNode* rotateRight(ListNode* head, int k){
			if (head == NULL || head->next == NULL)
				return head;

			ListNode* ptr = head;

			int n = 1;
			while (ptr->next != NULL){
				ptr = ptr->next;
				++n;
			}
			ptr->next = head;

			ptr = head;
			k = k % n;
			k = n - k;
			while (--k > 0){
				ptr = ptr->next;
			}
			head = ptr->next;
			ptr->next = NULL;
			return head;
		}
};

int main(int argc, char* args[]){
	ListNode *a = new ListNode(0);
	a->next = new ListNode(1);
	a->next->next = new ListNode(2);
	int k = 4;

	ListNode *ptr = Solution::rotateRight(a, k);
	while (ptr->next != NULL){
		cout << ptr->val << ", ";
		ptr = ptr->next;
	}
	cout << ptr->val << endl;

	return 0;
}

