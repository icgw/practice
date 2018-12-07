#include <vector>
using std::vector;
using std::min;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount){
            const int Max = amount + 1;
            vector<int> dp(Max, Max);
            dp[0] = 0;
            for (int i = 1; i <= amount; ++i){
                for (auto& c : coins){
                    if (i - c >= 0)
                        dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
            return dp[amount] > amount ? - 1 : dp[amount];
        }
};
