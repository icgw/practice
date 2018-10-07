/* Given a binary tree, check whether it is a mirror of itself (i.e., symmetric
 * around its center).
 *
 * For example, this binary tree [1, 2, 2, 3, 4, 4, 3] is symmetric:
 * 		 	1
 * 		   / \
 * 		  2   2
 * 		 / \ / \
 * 		3  4 4  3
 *
 * But the following [1, 2, 2, null, 3, null, 3] is not:
 * 		1
 * 	   / \
 * 	  2   2
 * 	   \   \
 * 	    3   3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
		static bool isSymmetric(TreeNode* root){
			if (!root) return true;
			return dfs(root->left, root->right);
		}
		static bool dfs(TreeNode* lf, TreeNode* rt){
			if (!lf && !rt) return true;
			if ((!lf && rt) || (lf && !rt)) return false;
			if (lf->val != rt->val) return false;
			return dfs(lf->left, rt->right) &&
		 	   	dfs(lf->right, rt->left);
		}
};

int main(int argc, char *args[]){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2); root->right = new TreeNode(2);
	root->left->left = new TreeNode(3); root->right->right = new TreeNode(3);
	root->left->right = new TreeNode(4); root->right->left = new TreeNode(4);

	cout << Solution::isSymmetric(root) << endl;

	return 0;
}
