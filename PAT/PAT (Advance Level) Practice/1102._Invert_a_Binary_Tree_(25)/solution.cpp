#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
  int Id, Left, Right, Index, Level;
} treeNode[11];

int hasParent[11] = { 0 };

vector<int> inOrder;

void dfs(int root, int index, int level) {
  if (treeNode[root].Right != -1) dfs(treeNode[root].Right, 2 * index + 2, level + 1);
  inOrder.push_back(root);
  treeNode[root].Index = index;
  treeNode[root].Level = level;
  if (treeNode[root].Left != -1) dfs(treeNode[root].Left, 2 * index + 1, level + 1);
}

bool cmp(Node x, Node y) {
  return (x.Level < y.Level) || (x.Level == y.Level && x.Index > y.Index);
}

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    string left, right;
    cin >> left >> right;
    treeNode[i].Id = i;
    if (left != "-") {
      int child = stoi(left);
      treeNode[i].Left = child;
      hasParent[child] = 1;
    } else {
      treeNode[i].Left = -1;
    }
    if (right != "-"){
      int child = stoi(right);
      treeNode[i].Right = child;
      hasParent[child] = 1;
    } else {
      treeNode[i].Right = -1;
    }
  }
  
  int root = 0;
  while (hasParent[root] != 0) ++root;
  dfs(root, 0, 0);
  sort(treeNode, treeNode + N, cmp);
  for (int i = 0; i < N; ++i) {
    if (i != 0) cout << " ";
    cout << treeNode[i].Id;
  }
  cout << endl;
  
  for (int i = 0; i < N; ++i) {
    if (i != 0) cout << " ";
    cout << inOrder[i];
  }
  cout << endl;
  
  return 0;
}