/* Given a binary tree and a sum, find all root-to-leaf paths where each path's 
 * sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
 * Example:
 * 	Given the below binary tree and `sum = 22`,
 * 	         5
 * 	        / \
 * 	       4   8
 * 	      /   / \
 * 	     11  13  4
 * 	    /  \    / \
 * 	   7    2  5   1
 * 	Return:
 * 	[
 * 		[5, 4, 11, 2],
 * 		[5, 8, 4, 5]
 * 	]
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
		static vector<vector<int>> pathSum(TreeNode* root, int sum){
			vector<vector<int>> ans;
			vector<int> curr;
			pathSum(ans, root, curr, sum);
			return ans;
		}
		static void pathSum(vector<vector<int>>& ans, 
				TreeNode* root, vector<int> curr, int sum){
			if (!root) return ;
			int val = root->val;

			curr.push_back(val);
			if (val == sum && !root->left && !root->right){
				ans.push_back(curr);
				return ;
			}

			pathSum(ans, root->left, curr, sum - val);
			pathSum(ans, root->right, curr, sum - val);
		}
};

int main(int argc, char* argv[]){
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4); root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13); root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	vector<vector<int>> ans = Solution::pathSum(root, 22);
	for (auto& x : ans){
		for (auto& y : x){
			cout << y << " ";
		}
		cout << endl;
	}

	return 0;
}
