/* Given an integer n, return the number of trailing zeroes in n!.
 *
 * Example:
 *        Input: 5
 *       Output: 1
 *  Explanation: 5! = 120, one trailing zero.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */
#include <iostream>

using namespace std;

class Solution {
	public:
		static int trailingZeroes(int n){
			return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
		}
};

int main(int argc, char *argv[]){
	int n = 15;
	cout << Solution::trailingZeroes(n) << endl;
	return 0;
}
