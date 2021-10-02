#ifndef __DATA_STRUCTURES__
#define __DATA_STRUCTURES__

#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <vector>
using std::vector;

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void trimLeftTrailingSpaces(string &input){
    input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input){
    input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
    while (node && node->next) {
        std::cout << node->val << "->";
        node = node->next;
    }

    if (node) {
      std::cout << node->val << std::endl;
    } else {
      std::cout << "Empty LinkedList" << std::endl;
    }
}

TreeNode* stringToTreeNode(string input){
    trimRightTrailingSpaces(input);
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
