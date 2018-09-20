/* Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white,
 * and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this problem.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static void sortColors(vector<int>& nums){
			int s = 0;
			int t = nums.size() - 1;
			if (t == 0) return;

			while (s < t && nums[s] == 0) ++s;
			while (s < t && nums[t] == 2) --t;

			int curr = s;
			while (s <= t && curr <= t){
				if (nums[curr] == 0){
					nums[curr] = nums[s];
					nums[s] = 0;
					++s;
					curr = (s > curr ? s : curr);
				}
				else if (nums[curr] == 2){
					nums[curr] = nums[t];
					nums[t] = 2;
					--t;
				}
				else {
					++curr;
				}
			}
		}
};

int main(int argc, char* args[]){
	vector<int> a(6, 0);
	a[0] = 2; a[2] = 2; a[3] = 1; a[4] = 1;

	Solution::sortColors(a);
	for (auto& x : a){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
