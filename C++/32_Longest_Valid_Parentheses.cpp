/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 * Example 2:
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int longestValidParentheses(string s){
			int n = s.size(), currMax = 0, l;
			vector<int> dp(n, 0);
			for (int i = 1; i < n; ++i){
				l = i - dp[i - 1] - 1;
				if (s[i] == ')' && l >= 0 && s[l] == '('){
					dp[i] = dp[i - 1] + 2 + (l - 1 >= 0 ? dp[l - 1] : 0);
					if (dp[i] > currMax) currMax = dp[i];
				}
			}
			return currMax;
		}
};

int main(int argc, char *argv[]){
	string s;
	s = "(()";
	cout << Solution::longestValidParentheses(s) << endl;
	s = ")()())";
	cout << Solution::longestValidParentheses(s) << endl;
	return 0;
}
