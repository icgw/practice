/* Given a binay tree containing digits from `0-9' only, each root-to-leaf path 
 * could represent a number.
 * An example is the root-to-leaf path `1->2->3' which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
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
		static int sumNumbers(TreeNode* root){
			return dfs(root, 0);
		}
		static int dfs(TreeNode* root, int in){
			if (!root) return in;
			int s = 10 * in + root->val;
			if (!root->left && !root->right) return s;
			if (root->left && !root->right) 
				return dfs(root->left, s);
			if (!root->left && root->right)
				return dfs(root->right, s);
			return dfs(root->left, s) + dfs(root->right, s);
		}
};

int main(int argc, char* argv[]){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2); root->right = new TreeNode(3);
	cout << Solution::sumNumbers(root) << endl;
	return 0;
}
