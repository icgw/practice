/* Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * 	A binary tree in which the depth of the two subtrees of every node never 
 * 	differ by more than 1.
 *
 * Example:
 * 	Given the following tree [3, 9, 20, null, null, 15, 7]:
 * 	    3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *  Return true.
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
		static bool isBalanced(TreeNode* root){
			if (!root) return true;
			int ld, rd;
			ld = depth(root->left);
			rd = depth(root->right);
			int differ = (ld - rd > 0) ? (ld - rd) : (rd - ld);
			return !(differ > 1) && 
				(isBalanced(root->left) && isBalanced(root->right));
		}
		static int depth(TreeNode* root){
			if (!root) return 0;
			queue<TreeNode*> que;
			que.push(root);

			TreeNode* tmp;
			int d = 0;
			while (!que.empty()){
				for (int s = que.size(); s > 0; --s){
					tmp = que.front();
					que.pop();
					if (tmp->left) que.push(tmp->left);
					if (tmp->right) que.push(tmp->right);
				}
				++d;
			}
			return d;
		}
};

int main(int argc, char* argv[]){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);

	cout << Solution::isBalanced(root) << endl;

	return 0;
}
