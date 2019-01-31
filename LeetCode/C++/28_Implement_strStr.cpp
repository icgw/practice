/* Return the index of the first occurrence of needle in haystack, or `-1` if
 * needle is not part of haystack.
 */
#include <iostream>
using namespace std;

class Solution {
	public:
		static int strStr(string haystack, string needle) {
			if (needle.empty())
				return 0;
			if (needle.size() > haystack.size())
				return -1;

			int ans = -1;

			int n_len = needle.size();
			int len = haystack.size() - n_len + 1;
			bool flag;
			for (int i = 0; i < len; ++i){
				flag = true;
				for (int j = 0; j < n_len; ++j){
					if (haystack[i + j] != needle[j]){
						flag = false;
						break;
					}
				}
				if (flag){
					ans = i;
					break;
				}
			}
			return ans;
		}
};

int main(int argc, char* args[]){
	string haystack1 = "hello", needle1 = "ll";
	string haystack2 = "aaaaa", needle2 = "bba";

	cout << Solution::strStr(haystack1, needle1) << endl;
	cout << Solution::strStr(haystack2, needle2) << endl;
	
	return 0;
}
