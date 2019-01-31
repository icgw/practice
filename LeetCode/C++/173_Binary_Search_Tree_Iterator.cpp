/* Implement an iterator over a binary search tree (BST). Your iterator will be 
 * initialized with the root node of a BST.
 *
 * Calling `next()' will return the next smallest number in the BST.
 *
 * Note: `next()' and `hasNext()' should run in average O(1) time and uses O(h) 
 * memory, where h is the height of the tree.
 */
#include <iostream>
#include <stack>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
	public:
		BSTIterator(TreeNode *root){
			while (root){
				stk.push(root);
				root = root->left;
			}
		}

		/** @return whether we have a next smallest number */
		bool hasNext() {
			return !stk.empty();
		}

		/** @return the next smallest number */
		int next() {
			TreeNode *cur = stk.top(), *n;
			stk.pop();
			int sv = cur->val;
			n = cur->right;
			while (n){
				stk.push(n);
				n = n->left;
			}
			return sv;
		}
	private:
		stack<TreeNode*> stk;
};
