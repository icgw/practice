/* Given an array where elements are sorted in ascending order, convert it to a 
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 * 	Given the sorted array: [-10, -3, 0, 5, 9],
 * 	One possible answer is: [0, -3, 9, -10, null, 5], which represents the 
 * 	following height balanced BST:
 * 	       0
 * 	      / \
 * 	    -3   9
 *      /   /
 *    -10  5
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
		static TreeNode* sortedArrayToBST(vector<int>& nums){
			return sortedArrayToBST(nums, 0, nums.size() - 1);
		}

		static TreeNode* sortedArrayToBST(vector<int>& nums, int s, int e){
			if (s > e) return NULL;
			int m = (s + e) / 2;
			TreeNode *rt = new TreeNode(nums[m]);
			rt->left = sortedArrayToBST(nums, s, m - 1);
			rt->right = sortedArrayToBST(nums, m + 1, e);
			return rt;
		}
};

int main(int argc, char* argv[]){
	vector<int> nums(5, 0);
	nums[0] = -10; nums[1] = -3; nums[2] = 0; nums[3] = 5; nums[4] = 9;
	TreeNode *root = Solution::sortedArrayToBST(nums);
	return 0;
}
