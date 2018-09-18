/* Implement `int sqrt(int x)'.
 *
 * Compute and return the square root of x, where x is guaranteed to be a 
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and 
 * only the integer part of the result is returned.
 */ 
#include <iostream>
using namespace std;

class Solution {
	public:
		static int mySqrt(int x){
			if (x == 0)
				return 0;
			if (x < 4)
				return 1;
			int p = 4, n = 2;
			while (p <= x && p > 0){
				p += (n << 1) + 1;
				++n;
			}
			return (n - 1);
		}
};

int main(int argc, char* args[]){
	int a = 8;
	cout << Solution::mySqrt(a) << endl;

	int b = 2147395600;
	cout << Solution::mySqrt(b) << endl; // 46340

	return 0;
}
