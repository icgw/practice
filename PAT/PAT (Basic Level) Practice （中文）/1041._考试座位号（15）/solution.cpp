#include <iostream>
using namespace std;

int main() {
    string table[1005][2], s1, s2;
    int N; cin >> N;
    
    int t;
    for (int i = 0; i < N; ++i) {
        cin >> s1 >> t >> s2;
        table[t][0] = s1;
        table[t][1] = s2;
    }
    
    int M; cin >> M;
    for (int i = 0; i < M; ++i) {
        int testid; cin >> testid;
        cout << table[testid][0] << " " << table[testid][1] << endl;
    }
    
    return 0;
}