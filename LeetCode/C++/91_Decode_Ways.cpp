/* A message containing letters from `A-Z' is being encoded to numbers using the
 * following mapping:
 *
 * 	`A' -> 1
 * 	`B' -> 2
 * 	...
 * 	`Z' -> 26
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 */ 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		static int numDecodings(string s){
			int n = s.size();
			if (n < 1) return 0;
			if (s[0] == '0') return 0;
			vector<int> dp(n + 1, 0);
			dp[0] = 1; dp[1] = 1;
			for (int i = 1; i < n; ++i){
				dp[i + 1] = s[i] == '0' ? 0 : dp[i];
				if (s[i - 1] - '0' == 1 || 
						(s[i - 1] - '0' == 2 && s[i] - '0' <= 6)){
					dp[i + 1] += dp[i - 1];
				}
			}
			return dp.back();
		}

};

int main(int argc, char* args[]){
	string s1 = "226";
	cout << Solution::numDecodings(s1) << endl;

	string s2 = "12";
	cout << Solution::numDecodings(s2) << endl;

	string s3 = "0";
	cout << Solution::numDecodings(s3) << endl;

	string s4 = "102";
	cout << Solution::numDecodings(s4) << endl;

	string s5 = "10";
	cout << Solution::numDecodings(s5) << endl;

	string s6 = "012";
	cout << Solution::numDecodings(s6) << endl;

	string s7 = "230";
	cout << Solution::numDecodings(s7) << endl;

	string s8 = "301";
	cout << Solution::numDecodings(s8) << endl;

	return 0;
}
