#include "../data_structures.hpp"

class Solution {
    private:
        void dfs(TreeNode* root, int &out, bool &hasFound, int &curr, int k) {
            if (!root || hasFound) {
                return ;
            }

            dfs(root->left, out, hasFound, curr, k);
            curr++;
            if (curr == k) {
                out = root->val;
                hasFound = true;
            }
            dfs(root->right, out, hasFound, curr, k);
        }
    public:
        int kthSmallest(TreeNode* root, int k) {
            int ret = 0, curr = 0;
            bool hasFound = false;
            dfs(root, ret, hasFound, curr, k);
            return ret;
        }
};
