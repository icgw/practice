/* Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Example:
 * 	Input: [1, null, 2, 3]
 * 	  1
 * 	   \
 * 	    2
 * 	   /
 * 	  3
 * 	Output: [1, 2, 3]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */ 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		static vector<int> preorderTraversal(TreeNode* root){
			vector<int> tra;
			if (!root) return tra;
			stack<TreeNode*> stk;
			stk.push(root);
			TreeNode *tmp;
			while (!stk.empty()){
				tmp = stk.top();
				stk.pop();
				tra.push_back(tmp->val);
				if (tmp->right) stk.push(tmp->right);
				if (tmp->left) stk.push(tmp->left);
			}
			return tra;
		}
};

int main(int argc, char *argv[]){
	TreeNode* tree = new TreeNode(1);
	tree->left = new TreeNode(2); tree->right = new TreeNode(3);
	tree->left->left = new TreeNode(4); tree->left->right = new TreeNode(5);
	tree->right->left = new TreeNode(6); tree->right->right = new TreeNode(7);

	vector<int> ans = Solution::preorderTraversal(tree);
	for (auto& x : ans) cout << x << " ";
	cout << endl;

	return 0;
}
