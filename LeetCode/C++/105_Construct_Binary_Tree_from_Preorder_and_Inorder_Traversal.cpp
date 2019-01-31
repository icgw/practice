/* Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * 	You may assume that duplicates do not exist in the tree.
 * For example, given
 * 	preorder = [3, 9, 20, 15, 7]
 * 	inorder  = [9, 3, 15, 20, 7]
 * Return the following binary tree:
 * 	    3
 * 	   / \
 * 	  9  20
 * 	    /  \
 * 	   15   7
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
		static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
			return buildTree(preorder, 0, preorder.size(),
							inorder, 0, inorder.size());
		}

		static TreeNode* buildTree(vector<int>& preorder, int ps, int pe,
								vector<int>& inorder, int is, int ie){
			if (ps >= pe || is >= ie) return NULL;

			int val = preorder[ps];
			TreeNode *rt = new TreeNode(val);

			int k = 0;
			while (is + k < ie && inorder[is + k] != val) ++k;
			rt->left = buildTree(preorder, ps + 1, min(ps + k  + 1, pe),
								inorder, is, min(is + k, ie));
			rt->right = buildTree(preorder, ps + k + 1, pe,
								inorder, is + k + 1, ie);
			return rt;
		}
};

int main(int argc, char* argv[]){
	vector<int> pre(5, 0), in(5, 0);
	pre[0] = 3; pre[1] = 9; pre[2] = 20; pre[3] = 15; pre[4] = 7;
	in[0] = 9; in[1] = 3; in[2] = 15; in[3] = 20; in[4] = 7;

	TreeNode* root = Solution::buildTree(pre, in);
	queue<TreeNode*> que;
	que.push(root);
	int s;
	TreeNode* tmp;
	while (!que.empty()){
		for (int s = que.size(); s > 0; --s){
			tmp = que.front();
			cout << tmp->val << " ";
			que.pop();
			if (tmp->left) que.push(tmp->left);
			if (tmp->right) que.push(tmp->right);
		}
		cout << endl;
	}

	return 0;
}
