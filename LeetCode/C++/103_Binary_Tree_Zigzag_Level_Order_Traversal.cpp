/* Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (i.e., from left to right, then right to left for the next level and
 * alternate between).
 *
 * For example:
 * Given binary tree [3, 9, 20, null, null, 15, 7],
 *        3
 *       / \
 *      9  20
 *        /  \
 *       15   7
 * return its zigzag level order traversal as:
 * [
 * 	[3],
 * 	[20, 9],
 * 	[15, 7]
 * ]
 */ 
#include <iostream>
#include <vector>
#include <queue>
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
		static vector<vector<int>> zigzagLevelOrder(TreeNode* root){
			vector<vector<int>> ans;
			if (!root) return ans;
			queue<TreeNode*> que;
			que.push(root);
			bool left2right = false;
			TreeNode* tmp;
			while (!que.empty()){
				vector<int> add;
				stack<TreeNode*> stk;
				if (left2right){
					for (int s = que.size(); s > 0; --s){
						tmp = que.front();
						que.pop();
						add.push_back(tmp->val);
						if (tmp->right) stk.push(tmp->right);
						if (tmp->left)  stk.push(tmp->left);
					}
					left2right = false;
				} else {
					for (int s = que.size(); s > 0; --s){
						tmp = que.front();
						que.pop();
						add.push_back(tmp->val);
						if (tmp->left)  stk.push(tmp->left);
						if (tmp->right) stk.push(tmp->right);
					}
					left2right = true;
				}
				while (!stk.empty()){
					que.push(stk.top());
					stk.pop();
				}
				ans.push_back(add);
			}
			return ans;
		}
};

int main(int argc, char* arg[]){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9); root->right = new TreeNode(20);
	root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);

	vector<vector<int>> ans = Solution::zigzagLevelOrder(root);
	for (auto& x : ans){
		for (auto& y : x){
			cout << y << " ";
		}
		cout << endl;
	}

	return 0;
}
