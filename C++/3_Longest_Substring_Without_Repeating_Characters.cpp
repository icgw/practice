/* Given a string, find the length of the longest substring without repeating
 * characters.
 */
#include <iostream>
#include <set>
using namespace std;

class Solution {
	public:
		static bool isRepeating(string str){
			for (int i = 0; i < str.size(); ++i){
				for (int j = i + 1; j < str.size(); ++j){
					if (str[i] == str[j]){
						return true;
					}
				}
			}
			return false;
		}

		/* Time Limit Exceeded */
		/*static int lengthOfLongestSubstring(string s) {
			int max = s.size() > 0 ? 1 : 0;
			for (int i = 0; i < s.size(); ++i){
				for (int len = s.size() - i; len > 0; --len){
					if (!isRepeating(s.substr(i, len)) && len > max){
						max = len;
					}
				}
			}
			return max;
		}*/

		static int lengthOfLongestSubstring(string s){
			int ans = 0, i = 0, j = 1;
			set<char> slidingWindow;
			int n = s.size();
			if (n != 0){
				slidingWindow.insert(s[0]);
				ans = 1;
			}
			while (i < n && j < n){
				if (slidingWindow.find(s[j]) == slidingWindow.end()){
					slidingWindow.insert(s[j++]);

					if (ans < j - i)
						ans = j - i;
				} else {
					slidingWindow.erase(s[i++]);
				}
			}
			return ans;
		}
};

int main(int argc, char *args[]){
	string a = "abcabcbb";
	string b = "bbbbb";
	string c = "pwwkew";
	string d = "au";

	cout << Solution::lengthOfLongestSubstring(a) << endl;
	cout << Solution::lengthOfLongestSubstring(b) << endl;
	cout << Solution::lengthOfLongestSubstring(c) << endl;
	cout << Solution::lengthOfLongestSubstring(d) << endl;

	return 0;
}
