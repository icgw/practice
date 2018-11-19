/* Write a function that takes an unsigned integer and returns the number of `1'
 * bits it has (also known as the Hamming weight).
 */
#include <iostream>

using namespace std;

class Solution {
	public:
		static int hammingWeight(uint32_t n){ // Needed improving.
			int ans = 0;
			for (int i = 0; i < 32; ++i){
				if (n & (1 << i)) ++ans;
			}
			return ans;
		}
};

int main(int argc, char *argv[]){
	int n = 11;
	cout << Solution::hammingWeight(n) << endl;
	return 0;
}
