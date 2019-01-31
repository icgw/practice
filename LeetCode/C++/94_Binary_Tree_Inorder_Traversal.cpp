/* Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 * 	Input: [1, null, 2, 3]
 * 		1
 * 		 \
 * 		  2
 * 		 /
 * 		3
 * 	Output: [1, 3, 2]
 */ 
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		static vector<int> inorderTraversal(TreeNode* root){
			vector<int> ans;
			if (!root) return ans;
			dfs(ans, root);
			return ans;
		}

		static void dfs(vector<int>& ans, TreeNode* root){
			if (root->left) dfs(ans, root->left);
			ans.push_back(root->val);
			if (root->right) dfs(ans, root->right);
		}
};

int main(int argc, char* args[]){
	TreeNode* rt = new TreeNode(1);
	rt->right = new TreeNode(2);
	rt->right->left = new TreeNode(3);

	vector<int> ans = Solution::inorderTraversal(rt);
	for (auto& x : ans){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
