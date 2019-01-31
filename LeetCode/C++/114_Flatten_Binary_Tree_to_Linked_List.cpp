/* Given a binary tree, flatten it to a linked list in-place.
 * For example, given the following tree:
 *       1
 *      / \
 *     2   5
 *    / \   \
 *   3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
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
		static void flatten(TreeNode* root){
			flatten(root, NULL);
		}

		static void flatten(TreeNode* root, TreeNode* add){
			if (!root) return ;
			if (!root->left && root->right){
				flatten(root->right, add);
				return ;
			}
			if (root->left && !root->right){
				flatten(root->left, add);
				root->right = root->left;
				root->left = NULL;
				return ;
			}
			if (!root->left && !root->right){
				root->right = add;
				return ;
			}

			flatten(root->left, root->right);
			flatten(root->right, add);
			root->right = root->left;
			root->left = NULL;
		}
};

int main(int argc, char* argv[]){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2); root->right = new TreeNode(5);
	root->left->left = new TreeNode(3); root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(6);

	Solution::flatten(root);

	TreeNode *ptr = root;
	while (ptr){
		cout << ptr->val << endl;
		ptr = ptr->right;
	}

	return 0;
}
