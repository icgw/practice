/* Given two binary trees, write a function to check if they are the same or not.
 *
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
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
		static bool isSameTree(TreeNode* p, TreeNode* q){
			if (!p && !q) return true;
			if ((!p && q) || (p && !q)) return false;
			if (p->val != q->val) return false;
			return isSameTree(p->left, q->left) &&
				isSameTree(p->right, q->right);
		}

};

int main(int argc, char* args[]){
	TreeNode *p = new TreeNode(1);
	p->left = new TreeNode(2);

	TreeNode *q = new TreeNode(1);
	q->right = new TreeNode(2);

	cout << Solution::isSameTree(p, q) << endl;

	return 0;
}
