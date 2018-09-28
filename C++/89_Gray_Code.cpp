/* The gray code is a binary numeral system where two successive values differ 
 * in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the 
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<int> grayCode(int n){
			vector<int> ans;
			int m = (1 << n);
			for (int i = 0; i < m; ++i)
				ans.push_back((i >> 1) ^ i);
			return ans;
		}
};

int main(int argc, char* args[]){
	int n = 3;
	vector<int> ans = Solution::grayCode(n);
	for (auto& x : ans){
		cout << x << endl;
	}
	return 0;
}


