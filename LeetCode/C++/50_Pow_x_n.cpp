/* Implement `pow(x, n)`, which calculates x raised to the power n (x^n).
 *
 * Example:
 * 	Input: 2, 10
 * 	Output: 1024
 */ 
#include <iostream>
#include <limits>

using namespace std;

class Solution {
	public:
		static double myPow(double x, int n){
			if (x == 1.0){
				return x;
			}
			if (x == -1.0){
				if (n % 2 == 1){
					return x;
				} else {
					return 1.0;
				}
			}

			double ans = 1.0;
			double y;
			int m;
			int sign = (n < 0) ? (-1) : 1;
			long long nn = n;
			nn = (nn > 0) ? nn : (-nn);

			double max = numeric_limits<double>::max();

			while (nn > 0){
				m = 1;
				y = x;
				while (nn > (m << 1)){
					y *= y;
					m <<= 1;
					if (y == 0 || y > max)
						break;
				}
				nn -= m;
				ans *= y;
				if (ans == 0)
					break;
			}
			if (sign < 0){
				return 1.0 / ans;
			}

			return ans;
		}
};

int main(int argc, char* args[]){
	double x1 = 2.0;
	int n1 = 10;
	cout << Solution::myPow(x1, n1) << endl;

	double x2 = 2;
	int n2 = -2;
	cout << Solution::myPow(x2, n2) << endl;

	double x3 = 0.00001;
	int n3 = 0x7fffffff;
	cout << Solution ::myPow(x3, n3) << endl;

	double x4 = 2.0;
	int n4 = 0x80000000;
	cout << Solution ::myPow(x4, n4) << endl;

	return 0;
}
