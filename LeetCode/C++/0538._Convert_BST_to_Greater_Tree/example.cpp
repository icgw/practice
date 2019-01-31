#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    TreeNode *ans = s.convertBST(stringToTreeNode("[5, 2, 13]"));
    prettyPrintTree(ans);
}
