#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int nums[10001] = { 0 };
    for (int i = 1; i <= N; ++i) {
        int tmp; cin >> tmp;
        nums[abs(tmp - i)]++;
    }
    
    for (int i = 10000; i >= 0; --i) {
        if (nums[i] >= 2) {
            cout << i << " " << nums[i] << endl;
        }
    }
    
    return 0;
}