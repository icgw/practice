#ifndef __DATA_STRUCTURES__
#define __DATA_STRUCTURES__

#include <queue>
#include <sstream>

using std::queue;

using std::string;
using std::to_string;
using std::stringstream;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void trimLeftTrailingSpaces(string &input){
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailinSpaces(string &input){
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(), input.end());
}

TreeNode* stringToTreeNode(string input){
    trimRightTrailinSpaces(input);
    trimLeftTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) return nullptr;

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true){
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) break;

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) break;

        trimLeftTrailingSpaces(item);
        if (item != "null"){
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }

    }
    return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true){
    if (node == nullptr){
        std::cout << "Empty tree\n";
        return ;
    }

    if (node->right) prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);

    std::cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
}

#endif
