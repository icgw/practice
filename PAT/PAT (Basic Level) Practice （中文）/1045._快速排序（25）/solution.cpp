#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> nums(N);
    vector<int> copy(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        copy[i] = nums[i];
    }

    sort(nums.begin(), nums.end());
    int prev_max = 0;
    int    count = 0;
    vector<int> out;
    for (int i = 0; i < N; ++i) {
        if (nums[i] == copy[i] && copy[i] > prev_max) {
            out.push_back(copy[i]);
            count++;
        }
        if (copy[i] > prev_max) {
            prev_max = copy[i];
        }
    }
    
    cout << count << endl;
    for (int i = 0; i < count; ++i) {
        if (i != 0) cout << " ";
        cout << out[i];
    }
    cout << endl;
    return 0;
}