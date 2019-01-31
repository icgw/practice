/* Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 * 
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
		static bool isPalindrome(ListNode* head){
			ListNode *slow, *fast, *left = NULL, *tmp;
			slow = fast = head;
			while (fast && fast->next){
				fast = fast->next->next;
				tmp = slow->next;
				slow->next = left;
				left = slow;
				slow = tmp;
			}
			if (fast) slow = slow->next;
			while (slow && left){
				if (slow->val != left->val) return false;
				slow = slow->next;
				left = left->next;
			}
			return true;
		}
};

int main(int argc, char *argv[]){
	ListNode *lst = new ListNode(1);
	lst->next = new ListNode(2);
	lst->next->next = new ListNode(2);
	lst->next->next->next = new ListNode(1);
	cout << Solution::isPalindrome(lst) << endl;
	return 0;
}
