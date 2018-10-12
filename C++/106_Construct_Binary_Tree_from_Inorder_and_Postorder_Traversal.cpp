/* Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * 	You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 * 	inorder = [9, 3, 15, 20, 7]
 * 	postorder = [9, 15, 7, 20, 3]
 * Return the following binary tree:
 *        3
 *       / \
 *      9  20
 *        /  \
 *       15   7
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
		static TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
			return buildTree(inorder, 0, inorder.size(),
					postorder, 0, postorder.size());
		}

		static TreeNode* buildTree(vector<int>& inorder, int is, int ie,
								vector<int>& postorder, int ps, int pe){
			if (is >= ie || ps >= pe) return NULL;

			int val = postorder[pe - 1], iv = is;
			TreeNode* root =  new TreeNode(val);
			while (inorder[iv] != val) ++iv;
			root->left = buildTree(inorder, is, iv, 
					postorder, ps, ps + (iv - is));
			root->right = buildTree(inorder, iv + 1, ie,
					postorder, ps + (iv - is), pe - 1);
			return root;
		}
};

int main(int argc, char* argv[]){

	return 0;
}
