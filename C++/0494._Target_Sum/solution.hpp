#include <vector>
using std::vector;

class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int S){
            int sum = 0;
            for (auto &n : nums) sum += n;
            if ((S + sum) % 2 == 1 || S > sum || S < -sum) return 0;

            int pos = (S + sum) / 2;
            vector<int> dp(pos + 1, 0);
            dp[0] = 1;
            for (auto &n : nums)
                for (int i = pos; i >= n; --i)
                    dp[i] += dp[i - n];
            return dp[pos];
        }

    /*************************************************************************
    public:
        int findTargetSumWays(vector<int>& nums, int S){
            if (nums.size() < 1) return 0;
            return dfs(nums, 0, S);
        }
    private:
        int dfs(vector<int>& nums, int i, int S){
            if (i == nums.size() - 1){
                if (nums[i] == S && S == 0) return 2;
                return nums[i] == S ? 1 : -nums[i] == S ? 1 : 0;
            }
            return dfs(nums, i + 1, S + nums[i]) + dfs(nums, i + 1, S - nums[i]);
        }
     **************************************************************************/
};
