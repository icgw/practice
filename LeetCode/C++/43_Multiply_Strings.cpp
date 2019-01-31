/* Given two non-negative integers `num1` and `num2` represented as strings, re-
 * turn the product of `num1` and `num2`, also represented as a string.
 *
 * Note:
 * 	1. The length of both `num1` and `num2` is < 110.
 * 	2. Both `num1` and `num2` contain only digits `0-9`.
 * 	3. Both `num1` and `num2` do not contain any leading zero, except the 
 * 	   number 0 itself.
 * 	4. You must not use any built-in BigInteger library or convert the inputs to
 * 	   integer directly.
 */ 
#include <iostream>

using namespace std;

// It worth considering.
class Solution {
	public:
		static string multiply(string num1, string num2){
			string ans(1000, '0');

			reverse(num1.begin(), num1.end());
			reverse(num2.begin(), num2.end());

			int temp;
			for (int i = 0; i < num1.size(); ++i){
				for (int j = 0; j < num2.size(); ++j){
					temp = (num1[i] - '0') * (num2[j] - '0');
					ans[i + j + 1] = (ans[i + j + 1] - '0' 
							+ (ans[i + j] - '0' + temp) / 10) + '0';
					ans[i + j] = (ans[i + j] - '0' + temp) % 10 + '0';
				}
			}

			string ans_out = ans.substr(0, ans.find_last_not_of('0') + 1);
			reverse(ans_out.begin(), ans_out.end());
			if (ans_out.size() == 0){
				return "0";
			}
			return ans_out;
		}
};

int main(int argc, char* args[]){
	string num1 = "123", num2 = "456";

	cout << Solution::multiply(num1, num2) << endl;
	

	return 0;
}
