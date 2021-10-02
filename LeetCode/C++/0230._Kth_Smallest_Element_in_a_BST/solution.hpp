#include "../data_structures.hpp"

class Solution {
private:
  int dfs(TreeNode* root, int& k) {
    if (root == nullptr) {
      return -1;
    }
    int x = dfs(root->left, k);
    if (k == 0) {
      return x;
    }
    --k;
    return k == 0 ? root->val : dfs(root->right, k);
  }
public:
  int kthSmallest(TreeNode* root, int k) {
    return dfs(root, k);
  }
};
