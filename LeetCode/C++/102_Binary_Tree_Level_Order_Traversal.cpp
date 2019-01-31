/* Given a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
 *
 * For example:
 * Given binary tree [3, 9, 20, null, null, 15, 7].
 *        3
 *       / \
 *      9  20
 *        /  \
 *       15   7
 * return its level order traversal as:
 * [
 * 	[3],
 * 	[9, 20],
 * 	[15, 7]
 * ]
 */ 
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		static vector<vector<int>> levelOrder(TreeNode* root){
			queue<TreeNode*> que;
			vector<vector<int>> ans;
			if (!root) return ans;
			que.push(root);
			TreeNode* tmp;
			while (!que.empty()){
				vector<int> add;
				for (int s = que.size(); s > 0; --s){
					tmp = que.front();
					que.pop();
					if (tmp->left) que.push(tmp->left);
					if (tmp->right) que.push(tmp->right);
					add.push_back(tmp->val);
				}
				ans.push_back(add);
			}
			return ans;
		}
};

int main(int argc, char* args[]){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9); root->right = new TreeNode(20);
	root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);

	vector<vector<int>> ans = Solution::levelOrder(root);
	for (auto& x : ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
