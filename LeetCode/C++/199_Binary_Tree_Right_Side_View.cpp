/* Given a binary tree, imagine yourself standing on the right side of it, 
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *   Input: [1, 2, 3, null, 5, null, 4]
 *  Output: [1, 3, 4]
 *  Exaplanation:
 *  
 *       1          <---
 *      / \
 *     2   3        <---
 *      \   \
 *       5   4      <---
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
		static vector<int> rightSideView(TreeNode* root){
			vector<int> ans;
			if (!root) return ans;
			queue<TreeNode*> q;
			q.push(root);
			int c;
			TreeNode *tmp;
			while (!q.empty()){
				c = q.size();
				tmp = q.back();
				ans.push_back(tmp->val);
				while (c > 0){
					tmp = q.front();
					q.pop();
					if (tmp->left) q.push(tmp->left);
					if (tmp->right) q.push(tmp->right);
					--c;
				}
			}
			return ans;
		}
};

int main(int argc, char *argv[]){
	TreeNode *t = new TreeNode(1);
	t->left = new TreeNode(2); t->right = new TreeNode(3);
	t->left->right = new TreeNode(5); t->right->right = new TreeNode(4);
	vector<int> ans = Solution::rightSideView(t);
	for (auto& x : ans){
		cout << x << endl;
	}
	return 0;
}
