/* Given a 32-bit signed integer, reverse digits of an integer.
 */
#include <iostream>
using namespace std;

class Solution {
	public:
		static int reverse(int x) {
			int r = 0, y;
			int ans = r;

			int maxInt = 0x0ccccccc;

			y = ((x > 0) ? x : -x);

			while (y > 0){
				r = y % 10;
				y = y / 10;
				if (ans > maxInt || (ans == maxInt && r > 7)){
					ans = 0;
				} else {
					ans = ans * 10 + r;
				}
			}

			return ((x > 0) ? ans : -ans);
		}
};

int main(int argc, char *args[]){
	int a = 123;
	int b = -123;
	int c = 120;
	int d = 1534236469;

	cout << Solution::reverse(a) << endl;
	cout << Solution::reverse(b) << endl;
	cout << Solution::reverse(c) << endl;
	cout << Solution::reverse(d) << endl;

	return 0;
}
