/* Implement `atoi` which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this charac-
 * ters, takes an optional initial plus or minus sign followed by as many num-
 * erical value.
 *
 * The string can contain additional characters after those that form the inte-
 * gral number, which are ignored and have no effect on the behavior of this
 * function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid in-
 * tegral number, or if no such sequence exists because either str is empty or
 * it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 *   + Only the space character ' ' is considered as whitespace character.
 *   + Assume we are dealing with an environment which could only store integers
 *   within the 32-bit signed integer range: [-2^{31}, 2^{31} - 1]. If the nu-
 *   merical value is out of the range of representable values, INT_MAX
 *   (2^{31} - 1) or INT_MIN (-2^{31}) is returned.
 */ 
#include <iostream>
using namespace std;

class Solution {
	public:
		static int char2int(char ch){
			if (ch >= '0' && ch <= '9')
				return (int) ch - '0';

			if (ch == '-')
				return -1;

			if (ch == '+')
				return -2;

			return -3;
		}

		static int myAtoi(string str){
			int INTMAX = 0x7fffffff;
			int INTMIN = 0x80000000;

			int n = str.size();
			int k;
			for (int i = 0; i < n; ){
				if (str[i] == ' ')
					++i;
				else {
					k = i;
					break;
				}
			}

			if (char2int(str[k]) == -3)
				return 0;

			int sign = (char2int(str[k]) == -1) ? (-1) : 1;
			int j = (char2int(str[k]) >= 0) ? k : k + 1;
			long long ans = 0;

			while (j < n && char2int(str[j]) > -1){
				ans = 10 * ans + char2int(str[j]);
				if ((int) ans != ans){
					ans = (sign > 0) ? INTMAX : INTMIN;
					break;
				}
				++j;
			}

			ans = sign * ans;
			if ((int) ans != ans){
				return sign > 0 ? INTMAX : INTMIN;
			}

			return (int) ans;
		}
};

int main(int argc, char *args[]){
	string a = "42";
	string b = "   -42";
	string c = "4193 with words";
	string d = "words and 987";
	string e = "-91283472332";
	string f = "1";
	string g = "+1";
	string h = "18446744073709551617";

	cout << Solution::myAtoi(a) << endl;
	cout << Solution::myAtoi(b) << endl;
	cout << Solution::myAtoi(c) << endl;
	cout << Solution::myAtoi(d) << endl;
	cout << Solution::myAtoi(e) << endl;
	cout << Solution::myAtoi(f) << endl;
	cout << Solution::myAtoi(g) << endl;
	cout << Solution::myAtoi(h) << endl;

	return 0;
}
