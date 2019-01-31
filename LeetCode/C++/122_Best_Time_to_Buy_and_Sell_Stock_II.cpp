/* Say you have an array for which the i^{th} element is the prices of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many 
 * transactions as you like (i.e., buy one and sell one share of the stock 
 * multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int maxProfit(vector<int>& prices){
			int n = prices.size();
			if (n < 2) return 0;
			vector<int> dp(n, 0);
			int max = 0, tmp;
			for (int i = 1; i < n; ++i){
				for (int j = 0; j < i; ++j){
					tmp = prices[i] - prices[j] + dp[j];
					if (tmp > max) max = tmp;
				}
				dp[i] = max;
			}
			return dp[n - 1];
		}
};

int main(int argc, char* argv[]){
	vector<int> prices(6, 0);
	prices[0] = 7; prices[1] = 1; prices[2] = 5; 
	prices[3] = 3; prices[4] = 6; prices[5] = 4;
	cout << Solution::maxProfit(prices) << endl;
	return 0;
}
