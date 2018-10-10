/* Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root
 * node down to the farthest leaf node.
 *
 * Note: A leaf is a node with no children.
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
		static int maxDepth(TreeNode* root){
			int depth = 0;
			if (!root) return depth;

			queue<TreeNode*> que;
			que.push(root);
			TreeNode* tmp;

			while (!que.empty()){
				++depth;
				for (int s = que.size(); s > 0; --s){
					tmp = que.front();
					que.pop();
					if (tmp->left) que.push(tmp->left);
					if (tmp->right) que.push(tmp->right);
				}
			}
			return depth;
		}
};

int main(int argc, char* argv[]){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9); root->right = new TreeNode(20);
	root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);

	cout << Solution::maxDepth(root) << endl;

	return 0;
}
