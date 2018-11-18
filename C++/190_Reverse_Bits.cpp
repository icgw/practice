/* Reverse bits of a given 32 bits unsigned integer.
 *
 * Example:
 *   Input: 43261596
 *  Output: 964176192
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */
#include <iostream>

using namespace std;

class Solution {
	public:
		static uint32_t reverseBits(uint32_t n){
			uint32_t rev = 0;
			for (int i = 0, j = 31; i < 32; ++i, --j){
				if (n & (1 << j)){
					rev |= (1 << i);
				}
			}
			return rev;
		}
};

int main(int argc, char *argv[]){
	uint32_t i = 43261596;
	cout << Solution::reverseBits(i) << endl;
	return 0;
}
