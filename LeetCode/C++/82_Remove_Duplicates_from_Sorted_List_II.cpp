/* Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 *
 * Example:
 * 	Input: 1->2->3->3->4->4->5
 * 	Output: 1->2->5
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
			int preVal = head->val - 1, curVal;
			ListNode* ptr = head;
			curVal = ptr->val;
			ListNode* ptrBack = head->next;
			if (ptrBack->next == NULL){
				if (ptr->val == ptrBack->val) return ptrBack->next;
			}
			while (ptrBack->next != NULL && 
					(curVal == preVal || curVal == ptrBack->val)){
				ptr = ptrBack;
				ptrBack = ptrBack->next;

				preVal = curVal;
				curVal = ptr->val;
			}
			if (ptrBack->next == NULL){
				if (curVal == preVal && curVal != ptrBack->val)
					ptr = ptrBack;
				else if (curVal == ptrBack->val)
					ptr = NULL;
			}
			head = ptr;
			if (head == NULL) return head;

			preVal = head->val;
			ListNode* curPtr = ptr->next;
			if (ptr->next == NULL) return head;
			curVal = curPtr->val;
			ListNode* backPtr = curPtr->next;
			while (curPtr->next != NULL){
				if (curVal != preVal && curVal != backPtr->val){
					ptr->next = curPtr;
					ptr = ptr->next;
				}
				curPtr = curPtr->next;
				backPtr = curPtr->next;
				preVal = curVal;
				curVal = curPtr->val;
			}
			if (curVal != preVal)
				ptr->next = curPtr;
			else
				ptr->next = NULL;
			return head;
		}
};

int main(int argc, char* args[]){
	ListNode *list = new ListNode(1);
	list->next = new ListNode(2);
	list->next->next = new ListNode(3);
	list->next->next->next = new ListNode(3);
	list->next->next->next->next = new ListNode(4);
	list->next->next->next->next->next = new ListNode(4);
	list->next->next->next->next->next->next = new ListNode(5);

	ListNode *head = Solution::deleteDuplicates(list);
	ListNode *ptr = head;
	while (ptr->next != NULL){
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout << ptr->val << endl;

	return 0;
}
