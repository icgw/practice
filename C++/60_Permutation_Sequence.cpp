/* Given n and k, return the k^{th} permutation sequence.
 * Note:
 * 	+ Given n will be between 1 and 9 inclusive.
 * 	+ Given k will be between 1 and n! inclusive.
 */ 
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
	public:
		static string getPermutation(int n, int k){
			string ans = "";
			for (int i = 1; i <= n; ++i){
				ans.push_back('0' + i);
			}

			int j, p;
			for (int i = 1; i < k; ++i){
				j = n - 1;
				while (j > 0 && ans[j - 1] > ans[j]){
					--j;
				}
				sort(ans.begin() + j, ans.end());
				p = j;
				while (ans[p] < ans[j - 1]){
					++p;
				}
				swap(ans[j - 1], ans[p]);
			}
			return ans;
		}
};

int main(int argc, char* args[]){
	int n = 4, k = 9;
	cout << Solution::getPermutation(n, k) << endl;
	return 0;
}
