/* Given two integers `dividend` and `divisor`, divide two integers without
 * using multiplication, division and mod operator.
 *
 * Return the quotient after dividing `dividend` by `divisor`.
 *
 * The integer division should truncate toward zero.
 */ 
#include <iostream>
using namespace std;

class Solution {
	public:
		static int divide(int dividend, int divisor) {
			if (dividend == 0
					|| (dividend > 0 && divisor > 0 && divisor > dividend)
					|| (dividend < 0 && divisor < 0 && dividend > divisor))
				return 0;

			if (divisor == 1)
				return dividend;

			bool left, right;
			long long dd, dv;
			if (dividend > 0){
				left = true;
				dd = (long long) dividend;
			} else {
				left = false;
				dd = 0 - (long long) dividend;
			}

			if (divisor > 0){
				right = true;
				dv = (long long) divisor;
			} else {
				right = false;
				dv = 0 - (long long) divisor;
			}

			// divisor == -1
			long long ans = 0;
			dfs(dd, dv, ans);

			if (left ^ right){
				return 0 - (int) ans;
			}

			if (ans > INT_MAX)
				return INT_MAX;

			return (int) ans;
		}

		static void dfs(long long dividend, long long divisor, 
				long long& q){
			if (dividend < divisor)
				return;

			if (dividend == divisor){
				++q;
				return;
			}

			long long add = 1, pre_add = 1, d = divisor, pre = divisor;
			while (divisor < dividend){
				pre = divisor;
				pre_add = add;

				divisor += divisor;
				add += add;
			}

			q = q + add - pre_add;
			dfs(dividend - pre, d, q);
		}
};

int main(int argc, char* args[]){
	int dividend1 = 10, divisor1 = 3;
	int dividend2 = 7, divisor2 = -3;
	int dividend3 = 0x80000000, divisor3 = -1;

	cout << Solution::divide(dividend1, divisor1) << endl;
	cout << Solution::divide(dividend2, divisor2) << endl;
	cout << Solution::divide(dividend3, divisor3) << endl;

	return 0;
}
