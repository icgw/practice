/* Say you hava an array for which the i^{th} element is the price of a given 
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy one
 * and sell one share of the stock), design an algorithm to find the maximum 
 * profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example:
 * 	Input: [7, 1, 5, 3, 6, 4]
 * 	Output: 5
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int maxProfit(vector<int>& prices){ // Bad Idea
			int n = prices.size() - 1;
			if (n < 1) return 0;
			int max = 0, curr;
			for (int s = n; s > 0; --s){
				for (int i = 0; i < s; ++i){
					curr = prices[s] - prices[i];
					if (curr > max) max = curr;
				}
			}
			return max;
		}
};

int main(int argc, char* argv[]){
	vector<int> nums(6, 0);
	nums[0] = 7; nums[1] = 1; nums[2] = 5; nums[3] = 3;
	nums[4] = 6; nums[5] = 4;
	cout << Solution::maxProfit(nums) << endl;
	return 0;
}
