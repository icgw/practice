#include <vector>
using std::vector;
using std::max;

class Solution {
    public:
        int maxProfit(vector<int>& prices){
            int n = prices.size();
            if (n <= 1) return 0;
            int buy = - prices[0], sell = 0, pre_sell = 0, tmp;
            for (auto& p : prices){
                tmp  = sell;
                sell = max(buy + p, sell);
                buy  = max(pre_sell - p, buy);
                pre_sell = tmp;
            }
            return sell;
        }
};
