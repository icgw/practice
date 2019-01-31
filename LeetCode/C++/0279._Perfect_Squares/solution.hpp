#include <vector>
using std::vector;
using std::min;
using std::max;

class Solution {
    public:
        int numSquares(int n){
            if (n <= 0) return 0;
            static vector<int> dp {0};
            int m = dp.size();
            dp.resize(max(m, n + 1), INT_MAX);
            for (int i = 1; i * i <= n; ++i) dp[i * i] = 1;
            for (int i = max(1, m); i <= n; ++i){
                for (int p = 1, q = i - 1; p <= q; ++p, --q){
                    dp[i] = min(dp[i], dp[p] + dp[q]);
                }
            }
            return dp[n];
        }
};
