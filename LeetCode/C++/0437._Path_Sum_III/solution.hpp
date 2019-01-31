#include "../data_structures.hpp"

class Solution {
    public:
        int pathSum(TreeNode* root, int sum){
            if (!root) return 0;
            return dfs(root, sum)
                + pathSum(root->left, sum)
                + pathSum(root->right, sum);
        }

    private:
        int dfs(TreeNode* root, int sum){
            if (!root) return 0;
            int v = root->val;
            return (v == sum ? 1 : 0)
                + dfs(root->left, sum - v)
                + dfs(root->right, sum - v);
        }
};
