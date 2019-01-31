/* Given a binary tree
 * 	struct TreeLinkNode {
 * 		TreeLinkNode *left;
 * 		TreeLinkNode *right;
 * 		TreeLinkNode *next;
 * 	}
 * Populate each next pointer to point to its next right node. If there is no 
 * next right node, the next pointer should be to `NULL'.
 * Initially, all next pointers are set to `NULL'.
 *
 * Note:
 * 	+ You may only use constant extra space.
 * 	+ Recursive approach is fine, implicit stack space does not count as extra
 * 	  space for this problem.
 * 	+ You may assume that it is a perfect binary tree (i.e., all leaves are at 
 * 	  the same level, and every parent has two children).
 * Example:
 * 	Given the following perfect binary tree,
 * 	        1
 * 	       /  \
 * 	      2    3
 * 	     / \  / \
 * 	    4  5  6  7
 * 	After calling your function, the tree should look like:
 * 	        1 -> NULL
 * 	      /  \
 * 	     2 -> 3 -> NULL
 * 	    / \  / \
 * 	   4->5->6->7 -> NULL
 */ 
#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
	public:
		static void connect(TreeLinkNode *root){
			if (!root) return;
			queue<TreeLinkNode*> q;

			TreeLinkNode *tmp;
			q.push(root);
			while (!q.empty()){
				q.push(NULL);
				for (int s = q.size(); s > 1; --s){
					tmp = q.front();
					q.pop();
					tmp->next = q.front();
					if (tmp->left) q.push(tmp->left);
					if (tmp->right) q.push(tmp->right);
				}
				q.pop();
			}
		}
};

int main(int argc, char* argv[]){
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2); root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4); 
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);

	Solution::connect(root);

	TreeLinkNode *ptr = root, *tmp;
	while (ptr){
		tmp = ptr;
		while (tmp){
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
		ptr = ptr->left;
	}

	return 0;
}
