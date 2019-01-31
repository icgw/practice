/* Given a positive integer, return its corresponding column title as appear in 
 * an Excel sheet.
 *
 * For example:
 * 	1 -> A
 * 	2 -> B
 * 	3 -> C
 * 	...
 * 	26 -> Z
 * 	27 -> AA
 * 	28 -> AB
 * 	...
 *
 * Example:
 * 	 Input: 701
 * 	Output: "ZY"
 */
#include <iostream>

using namespace std;

class Solution {
	public:
		static string convertToTitle(int n){
			int r;
			string ans;
			while (n > 0){
				r = --n % 26;
				ans += ('A' + r);
				n /= 26;
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
};

int main(int argc, char *argv[]){
	int n = 701;
	cout << Solution::convertToTitle(n) << endl;
	return 0;
}
