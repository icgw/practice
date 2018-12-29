#include "../data_structures.hpp"
using std::max;

class Solution {
    private:
        int max_sum;

        int helper(TreeNode* root) {
            if (!root) return 0;
            int left  = helper(root->left);
            int right = helper(root->right);

            max_sum = max(max_sum, left + right + root->val);
            return max(0, max(left + root->val, right + root->val));
        }

    public:
        int maxPathSum(TreeNode* root) {
            max_sum = INT_MIN;
            helper(root);
            return max_sum;
        }
};
