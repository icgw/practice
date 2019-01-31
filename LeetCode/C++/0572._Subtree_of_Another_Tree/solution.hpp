#include "../data_structures.hpp"

class Solution {
    private:
        bool isSame(TreeNode* l, TreeNode* r){
            if (!l && !r) return true;
            if (!l || !r) return false;
            if (l->val != r->val) return false;
            return isSame(l->left, r->left) && isSame(l->right, r->right);
        }
    public:
        bool isSubtree(TreeNode* s, TreeNode* t){
            if (isSame(s, t)) return true;
            if (!s) return false;
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
};
