#include <iostream>
#include "solution.hpp"

void run_example() {
    Codec coder;
    string str = coder.serialize(stringToTreeNode("[1, 2, 3, null, null, 4, 5]"));
    TreeNode* root = coder.deserialize(str);
    prettyPrintTree(root);
}
