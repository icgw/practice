/* Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the 
 * number 0 itself.
 *
 * Example:
 * 	Input: [1, 2, 3]
 * 	Output: [1, 2, 4]
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<int> plusOne(vector<int>& digits){
			vector<int> ans;
			int res = 1, t;
			for (int i = digits.size() - 1; i >= 0; --i){
				ans.push_back((res + digits[i]) % 10);
				res = (res + digits[i]) / 10;
			}
			if (res == 1)
				ans.push_back(1);
			reverse(ans.begin(), ans.end());
			return ans;
		}
};

int main(int argc, char* args[]){
	vector<int> a(3, 0);
	a[0] = 1; a[1] = 2; a[2] = 3;

	vector<int> ans = Solution::plusOne(a);
	for (auto& x : ans){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
