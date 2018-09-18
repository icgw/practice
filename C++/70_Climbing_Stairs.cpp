/* You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can 
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * Example:
 * 	Input: 2
 * 	Output: 2
 * 	Explanation: There are two ways to climb to the top.
 * 		1. 1 step + 1 step;
 * 		2. 2 steps.
 */ 
#include <iostream>

using namespace std;

class Solution {
	public:
		static int climbStairs(int n){
			int a[3] = {0, 1, 2};
			while (n > 0){
				a[0] = a[1];
				a[1] = a[2];
				a[2] = a[0] + a[1];
				--n;
			}

			return a[0];
		}
};

int main(int argc, char* args[]){
	int a = 2, b = 3;
	cout << Solution::climbStairs(a) << endl;
	cout << Solution::climbStairs(b) << endl;
	return 0;
}

