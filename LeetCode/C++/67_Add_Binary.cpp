/* Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example:
 * 	Input: a = "11", b = "1"
 * 	Output: "100"
 */ 
#include <iostream>

using namespace std;

class Solution {
	public:
		static string addBinary(string a, string b){
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			int na = a.size(), nb = b.size();
			while (na < nb){
				a.push_back('0');
				++na;
			}
			while (nb < na){
				b.push_back('0');
				++nb;
			}
			
			string ans;
			int res = 0, t;
			for (int i = 0; i < na; ++i){
				t = res + (a[i] - '0') + (b[i] - '0');
				ans.push_back('0' + (t % 2));
				res = t / 2;
			}
			if (res == 1){
				ans.push_back('1');
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
};

int main(int argc, char* agrs[]){
	string a = "1010", b = "1011";
	cout << Solution::addBinary(a, b) << endl;

	string a2 = "11", b2 = "1";
	cout << Solution::addBinary(a2, b2) << endl;

	return 0;
}
