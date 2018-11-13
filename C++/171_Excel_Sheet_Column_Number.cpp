/* Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 * 	A -> 1
 * 	B -> 2
 * 	C -> 3
 * 	...
 * 	Z -> 26
 * 	AA -> 27
 * 	AB -> 28
 * 	...
 *
 * Example:
 *   Input: "ZY"
 *  Output: 701
 */
#include <iostream>

using namespace std;

class Solution {
	public:
		static int titleToNumber(string s){
			int ans = 0, p = 1;;
			for (int pos = s.size() - 1; pos >=0; --pos){
				ans += ((int) s[pos] - 'A' + 1) * p;
				p *= 26;
			}
			return ans;
		}
};

int main(int argc, char *argv[]){
	string s = "ZY";
	cout << Solution::titleToNumber(s) << endl;
	string s2 = "AB";
	cout << Solution::titleToNumber(s2) << endl;
	string s3 = "A";
	cout << Solution::titleToNumber(s3) << endl;
	return 0;
}
