/* Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 * 	+ The left subtree of a node contains only nodes with keys less than the 
 * 	  node's key.
 * 	+ The right subtree of a node contains only nodes with keys greater than 
 * 	  the node's key.
 * 	+ Both the left and right subtrees must also be binary search trees.
 * 
 * Example:
 * 	Input:
 * 		2
 * 	   / \
 * 	  1   3
 * 	Output: true
 */ 
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		static bool isValidBST(TreeNode* root){
			return isValidBST(root, LONG_MIN, LONG_MAX);
		}

		static bool isValidBST(TreeNode* root, long lo, long hi){
			if (!root) return true;
			if (root->val <= lo || root->val >= hi) return false;

			return isValidBST(root->left, lo, root->val) &&
				isValidBST(root->right, root->val, hi);
		}
};

int main(int argc, char* args[]){
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	cout << Solution::isValidBST(root) << endl;

	return 0;
}
