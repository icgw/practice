#include <vector>
using std::vector;

class Solution {
    public:
        bool canPartition(vector<int>& nums){
            int total = 0, n = nums.size();
            for (int i = 0; i < n; ++i) total += nums[i];
            if (total & 1) return false;
            int half = total >> 1;
            vector<bool> dp(half + 1);
            dp[0] = true;
            for (int i = 0; i < n; ++i){
                for (int j = half; j > 0; --j){
                    if (j >= nums[i]) dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
            return dp[half];
        }
};
