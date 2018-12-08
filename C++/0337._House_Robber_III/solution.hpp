#include "../data_structures.hpp"

using std::max;

class Solution {
    public:
        int rob(TreeNode* root){
            if (!root) return 0;
            TreeNode* l = root->left, *r = root->right;
            if (l && r) return max(rob(l) + rob(r),
                    root->val + rob(l->left) + rob(l->right) + rob(r->left) + rob(r->right));
            if (l) return max(rob(l), root->val + rob(l->left) + rob(l->right));
            if (r) return max(rob(r), root->val + rob(r->left) + rob(r->right));
            return root->val;
        }
};
