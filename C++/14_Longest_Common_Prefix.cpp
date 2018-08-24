/* Write a function to find the longest common prefix string amongst an array of
 * strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Note: All given inputs are in lowercase letters `a-z`.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static string longestCommonPrefix(vector<string>& strs) {
			if (strs.size() == 1){
				return strs[0];
			}
			if (strs.size() == 0){
				return "";
			}
			int i = 0;
			bool flag = true;
			char tmp;
			while (flag){
				for (int k = 0; k < strs.size() - 1; ++k){
					if (strs[k].length() <= i){
						flag = false;
						break;
					}
					if (strs[k][i] != strs[k + 1][i]){
						flag = false;
						break;
					}
				}
				if (flag)
					++i;
			}
			if (i == 0){
				return "";
			} 

			return strs[0].substr(0, i);
		}
};

int main(int argc, char *args[]) {
	string a[] = {"flower", "flow", "flight"};
	vector<string> aa(a, a + 3);

	cout << Solution::longestCommonPrefix(aa) << endl;

	return 0;
}
