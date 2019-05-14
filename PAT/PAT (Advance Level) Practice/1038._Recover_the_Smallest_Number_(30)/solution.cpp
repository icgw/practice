#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<string> nums (N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), [](string &a, string &b) -> bool {
        return a + b < b + a;
    });

    string ret = "";
    for (auto &s : nums) {
        ret += s;
    }
    
    int id = 0;
    while (ret.size() != 0 && ret[id] == '0') {
        ++id;
    }

    if (id < ret.size()) {
        cout << ret.substr(id) << "\n";
    } else {
        cout << "0\n";
    }

    return 0;
}