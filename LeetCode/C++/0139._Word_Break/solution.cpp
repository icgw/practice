/* Given a non-empty string s and a dictionary wordDict containing a list of 
 * non-empty words, determine if s can be segmented into a space-separated 
 * sequence of one or more dictionary words.
 *
 * Note:
 * 	+ The same word in the dictionary may be reused multiple times in the 
 * 	  segmentation.
 * 	+ You may assume the dictionary does not contain duplicate words.
 * 
 * Example 1:
 * 	Input: s = "leetcode", wordDict = ["leet", "code"]
 * 	Output: true
 * 
 * Example 2:
 * 	Input: s = "catsandog". wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 	Output: false
 */ 
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	public:
		static bool wordBreak(string s, vector<string>& wordDict){
			unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
			int n = s.size();
			vector<bool> dp(n + 1, false);
			dp[0] = true;
			for (int i = 1; i <= n; ++i){
				for (int j = 0; j < i; ++j){
					if (dp[j] && wordSet.count(s.substr(j, i - j))){
						dp[i] = true;
						break;
					}
				}
			}
			return dp.back();
		}
};

int main(int argc, char *argv[]){
	string s = "leetcode";
	vector<string> wordDict {"leet", "code"};

	cout << Solution::wordBreak(s, wordDict) << endl;

	return 0;
}
