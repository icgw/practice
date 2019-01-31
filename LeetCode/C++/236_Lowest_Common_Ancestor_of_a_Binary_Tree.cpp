/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” 
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6      _2       0       8
 *          /  \
 *          7   4
 * Example 1:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 * Example 2:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
 *              according to the LCA definition.
 *
 * Note:
 *  + All of the nodes' values will be unique.
 *  + p and q are different and both values will exist in the binary tree.
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
		static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
			if (!root || root == p || root == q) return root;
			TreeNode *left = lowestCommonAncestor(root->left, p, q);
			TreeNode *right = lowestCommonAncestor(root->right, p, q);
			return !left ? right : !right ? left : root;
		}
};

int main(int argc, char *argv[]){
	TreeNode *tree = new TreeNode(3);
	tree->left = new TreeNode(5); tree->right = new TreeNode(1);
	tree->left->left = new TreeNode(6); tree->left->right = new TreeNode(2);
	tree->right->left = new TreeNode(0); tree->right->right = new TreeNode(8);
	tree->left->right->left = new TreeNode(7); tree->left->right->right = new TreeNode(4);
	TreeNode *p = tree->left, *q = tree->right;
	TreeNode *ans = Solution::lowestCommonAncestor(tree, p, q);
	cout << ans->val << endl; // output: 3
	return 0;
}
