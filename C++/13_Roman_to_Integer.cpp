/* Roman numberals are represented by seven different symbols: I, V, X, L, C, D 
 * and M.
 *
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 */ 
#include <iostream>
using namespace std;

class Solution {
	public:
		static int char2Int(char ch) {
			int v;
			switch (ch) {
				case 'I': v = 1;
						  break;
				case 'V': v = 5;
						  break;
				case 'X': v = 10;
						  break;
				case 'L': v = 50;
						  break;
				case 'C': v = 100;
						  break;
				case 'D': v = 500;
						  break;
				case 'M': v = 1000;
						  break;
			}
			return v;
		}
		static int romanToInt(string s) {
			int ans = 0, c, tmp;
			for (int i = 0; i < s.size(); ++i) {
				c = char2Int(s[i]);
				if (c == 1 && i < s.size() - 1) {
					tmp = char2Int(s[i + 1]);
					if (tmp > c) {
						c = -c;
					}
				}

				if (c == 10 && i < s.size() - 1) {
					tmp = char2Int(s[i + 1]);
					if (tmp > c) {
						c = -c;
					}
				}

				if (c == 100 && i < s.size() - 1) {
					tmp = char2Int(s[i + 1]);
					if (tmp > c) {
						c = -c;
					}
				}
				ans += c;
			}
			return ans;
		}
};

int main(int argc, char *args[]) {
	string a = "III";
	string b = "IV";
	string c = "IX";
	string d = "LVIII";
	string e = "MCMXCIV";

	cout << Solution::romanToInt(a) << endl;
	cout << Solution::romanToInt(b) << endl;
	cout << Solution::romanToInt(c) << endl;
	cout << Solution::romanToInt(d) << endl;
	cout << Solution::romanToInt(e) << endl;

	return 0;
}



