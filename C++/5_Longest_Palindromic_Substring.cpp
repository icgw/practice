/* Given a string s, find the longest palindromic substring in s. You may 
 * assume that the maximum length of s is 1000.
 */ 
#include <iostream>
using namespace std;

class Solution {
	public:
		static string longestPalindrome(string s){
			int n = s.size();
			string ans;
			if (n > 0){
				ans = s[0];
			} else {
				return "";
			}
				
			for (int i = 0, j = 1; i > -1 && j < n; ){
				if (s[i] == s[j]){
					ans = j - i + 1 > ans.size() ? s.substr(i, j - i + 1) : ans;
					if (i > 0){
						--i;
						++j;
					} else {
						i = (i + j + 1) / 2;
						j = i + 1;
					}
				} else {
					i = (i + j + 1) / 2;
					j = i + 1;
				}
			}

			for (int i = 0, j = 2; i > -1 && j < n; ){
				if (s[i] == s[j]){
					ans = j - i + 1 > ans.size() ? s.substr(i, j - i + 1) : ans;
					if (i > 0){
						--i;
						++j;
					} else {
						i = (i + j) / 2;
						j = i + 2;
					}
				} else {
					i = (i + j) / 2;
					j = i + 2;
				}
			}
			return ans;
		}
};

int main(int argc, char *args[]){
	string a = "babad";
	string b = "cbbd";
	string c = "c";
	string d = "aaabaaaa";
	string e = "ccc";
	string f = "aaaa";

	cout << Solution::longestPalindrome(a) << endl;
	cout << Solution::longestPalindrome(b) << endl;
	cout << Solution::longestPalindrome(c) << endl;
	cout << Solution::longestPalindrome(d) << endl;
	cout << Solution::longestPalindrome(e) << endl;
	cout << Solution::longestPalindrome(f) << endl;

	return 0;
}
