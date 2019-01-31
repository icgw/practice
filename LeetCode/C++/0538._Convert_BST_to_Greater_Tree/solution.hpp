#include "../data_structures.hpp"

class Solution {
    private:
        int curr_sum = 0;

    public:
        TreeNode* convertBST(TreeNode* root){
            if (!root) return root;
            convertBST(root->right);
            root->val = (curr_sum += root->val);
            convertBST(root->left);
            return root;
        }
};
