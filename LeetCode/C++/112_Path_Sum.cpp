/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 * Example:
 * 	Given the below binary tree and `sum = 22`,
 * 	         5
 * 	        / \
 * 	       4   8
 * 	      /   / \
 * 	     11  13  4
 * 	    /  \      \
 * 	   7    2      1
 * 	return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.
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
		static bool hasPathSum(TreeNode* root, int sum){
			if (!root) return false;
			int val = root->val;
			if (!root->left && !root->right) return (sum == val);
			return hasPathSum(root->left, sum - val) ||
				hasPathSum(root->right, sum - val);
		}
};

int main(int argc, char* argv[]){
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4); root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13); root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->right = new TreeNode(1);
	cout << Solution::hasPathSum(root, 22) << endl;
	return 0;
}
