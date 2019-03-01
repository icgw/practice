#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> rope(N);
    for (int i = 0; i < N; ++i) {
        cin >> rope[i];
    }
    
    sort(rope.begin(), rope.end());
    
    int result = rope[0];
    for (int i = 1; i < rope.size(); ++i) {
        result = (result + rope[i]) / 2;
    }
    
    cout << result << endl;
    
    return 0;
}