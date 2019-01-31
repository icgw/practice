/* Determine whether an integer is a palindrome. An integer is palindrome when
 * it reads the same backward as forward.
 */ 
#include <iostream>
using namespace std;

class Solution {
	public:
		static bool isPalindrome(int x){
			cout << x << endl;
			if (x < 0)
				return false;

			long long y = x;
			long long z = 0;
			int r = 0;

			while (y != 0){
				r = y % 10;
				y = y / 10;
				z = 10 * z + r;
			}

			return (z == x);
		}
};

int main(int argc, char *args[]){
	int a = 121;
	int b = -121;
	int c = 10;

	cout << Solution::isPalindrome(a) << endl;
	cout << Solution::isPalindrome(b) << endl;
	cout << Solution::isPalindrome(c) << endl;

	return 0;
}
