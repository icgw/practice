/* Given an integer n, generate all structurally unique BST's (binary search 
 * trees) that store values 1 ... n.
 *
 * Example:
 * 	Input: 3
 * 	Output: 
 * 		[
 * 			[1, null, 3, 2],
 * 			[3, 2, null, 1],
 * 			[3, 1, null, null, 2],
 * 			[2, 1, 3],
 * 			[1, null, 2, null, 3]
 * 		]
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
		static vector<TreeNode*> generateTrees(int n) {
			if (n < 1){
				vector<TreeNode*> out;
				return out;
			}
			return *dfs(1, n);
		}
		static vector<TreeNode*>* dfs(int start, int end){
			vector<TreeNode*> *subTree = new vector<TreeNode*>();
			if (start > end) subTree->push_back(NULL);

			vector<TreeNode*> *leftTree, *rightTree;
			for (int i = start; i <= end; ++i){
				leftTree = dfs(start, i - 1);
				rightTree = dfs(i + 1, end);
				for (int l = 0; l < leftTree->size(); ++l){
					for (int r = 0; r < rightTree->size(); ++r){
						TreeNode *node = new TreeNode(i);
						node->left = (*leftTree)[l];
						node->right = (*rightTree)[r];
						subTree->push_back(node);
					}
				}
			}
			return subTree;
		}
};

int main(int argc, char* args[]){
	int n = 3;
	vector<TreeNode*> vecTN = Solution::generateTrees(n);
	// No test...

	return 0;
}
