#include <iostream>
#include <vector>
using namespace std;

int numOfLevel[100] = { 0 };
vector<int> parents[100];

void dfs(int index, int level) {
    numOfLevel[level]++;
    for (int i = 0; i < parents[index].size(); ++i){
        dfs(parents[index][i], level + 1);
    }
    return ;
}

int main(){
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int p, nChild; cin >> p >> nChild;
        for (int k = 0; k < nChild; ++k) {
            int c; cin >> c;
            parents[p].push_back(c);
        }
    }
    
    int maxnum = 0, maxlevel = 1;
    dfs(1, 1);
    for (int i = 1; i < 100; ++i) {
        if (numOfLevel[i] > maxnum) {
            maxnum     = numOfLevel[i];
            maxlevel = i;
        }
    }
    
    cout << maxnum << " " << maxlevel << endl;
    
    return 0;
}