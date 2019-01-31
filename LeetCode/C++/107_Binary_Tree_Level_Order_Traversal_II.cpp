/* Given a binary tree, return the bottom-up level order traversal of its nodes'
 * values. (i.e., from left to right, level by level from leat to root).
 *
 * For example:
 * 	Given binary tree [3, 9, 20, null, null, 15, 7],
 * 	     3
 * 	    / \
 * 	   9  20
 * 	     /  \
 * 	    15   7
 *  return its bottom-up level order traversal as:
 *  [
 *  	[15, 7],
 *  	[9, 20],
 *  	[3]
 *  ]
 */ 
#include <iostream>
#include <vector>

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
		static vector<vector<int>> levelOrderBottom(TreeNode* root){
			vector<vector<int>> ans;
			if (!root) return ans;

			queue<TreeNode*> que;
			TreeNode* tmp;
			que.push(root);
			while (!que.empty()){
				vector<int> add;
				for (int s = que.size(); s > 0; --s){
					tmp = que.front();
					que.pop();
					add.push_back(tmp->val);
					if (tmp->left) que.push(tmp->left);
					if (tmp->right) que.push(tmp->right);
				}
				ans.push_back(add);
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
};

int main(int argc, char* argv[]){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);

	vector<vector<int>> ans = Solution::levelOrderBottom(root);
	for (auto& x : ans){
		for (auto& y : x){
			cout << y << " ";
		}
		cout << endl;
	}

	return 0;
}
