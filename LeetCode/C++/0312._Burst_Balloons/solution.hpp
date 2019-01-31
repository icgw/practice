#include <vector>
using std::vector;
using std::max;

class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            int sz = nums.size();

            vector<int> inums(nums.begin(), nums.end());
            inums.insert(inums.begin(), 1);
            inums.push_back(1);

            vector<vector<int>> dp(inums.size(), vector<int>(inums.size(), 0));
            for (int len = 1; len <= sz; ++len) {
                for (int left = 1; left <= sz - len + 1; ++left) {
                    int right = left + len - 1;
                    for (int k = left; k <= right; ++k)
                        dp[left][right] = max(dp[left][right],
                                inums[left - 1] * inums[k] * inums[right + 1]
                                + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
            return dp[1][sz];
        }
};
