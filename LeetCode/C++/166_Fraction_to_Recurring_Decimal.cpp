/* Given two integers representing the numerator and denominator of a fraction, 
 * return the fraction in string format.
 *
 * Example:
 * 	 Input: numerator = 2, denominator = 3
 * 	Output: "0.(6)"
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		static string fractionToDecimal(int numerator, int denominator){
			string dec;
			if ((numerator > 0 && denominator < 0) ||
					(numerator < 0 && denominator > 0)) dec = "-";
			long long n = abs((long long) numerator),
				 d = abs((long long) denominator);
			dec += to_string(n / d);
			long long rem = n % d;
			if (rem == 0) return dec;
			dec += ".";
			string s;
			unordered_map<long long, int> m;
			int pos = 0;
			while (rem != 0){
				s += to_string((rem * 10) / d);
				m[rem] = pos;
				rem = (rem * 10) % d;
				if (m.find(rem) != m.end()){
					s.insert(m[rem], "(");
					s += ")";
					return dec + s;
				}
				++pos;
			}
			return dec + s;
		}
};

int main(int argc, char *argv[]){
	int n = 2, d = 3;
	cout << Solution::fractionToDecimal(n, d) << endl;
	return 0;
}
