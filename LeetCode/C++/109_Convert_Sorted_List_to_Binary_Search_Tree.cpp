/* Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as binary tree in
 * which the depth of the two subtrees of every node never differ by more than 1.
 *
 * Example:
 * 	Given the sorted linked list: [-10, -3, 0, 5, 9],
 * 	One possible answer is: [0, -3, 9, -10, null, 5], which represents the 
 * 	following height balanced BST:
 * 	      0
 * 	     / \
 * 	   -3   9
 *     /   /
 *   -10  5
 */ 
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		static int find(ListNode *h, int pos){
			while (pos > 0){
				h = h->next;
				--pos;
			}
			return h->val;
		}

		static TreeNode* sortedListToBST(ListNode *head){
			if (!head) return NULL;
			int size = 0;
			ListNode *ptr = head;
			while (ptr->next){
				ptr = ptr->next;
				++size;
			}
			return sortedListToBST(head, size);
		}

		static TreeNode* sortedListToBST(ListNode *head, int size){
			if (!head || size < 0) return NULL;

			int mid = size / 2, k;

			TreeNode* root = new TreeNode(find(head, mid));

			root->left = sortedListToBST(head, mid - 1);
			k = mid;
			while (k > 0){
				head = head->next;
				--k;
			}
			root->right = sortedListToBST(head->next, size - mid - 1);
			return root;
		}
};

int main(int argc, char* argv[]){
	ListNode *lst = new ListNode(-10);
	lst->next = new ListNode(-3);
	lst->next->next = new ListNode(0);
	lst->next->next->next = new ListNode(5);
	lst->next->next->next->next = new ListNode(9);

	TreeNode* root = Solution::sortedListToBST(lst);

	queue<TreeNode*> q;
	TreeNode *tmp;
	q.push(root);
	while (!q.empty()){
		for (int s = q.size(); s > 0; --s){
			tmp = q.front();
			q.pop();
			cout << tmp->val << " ";
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
		}
		cout << endl;
	}

	return 0;
}
