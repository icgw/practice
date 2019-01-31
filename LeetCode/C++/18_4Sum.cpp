/* Given an array `nums` of n integers and an integer `target`, are there ele-
 * ments a, b, c and d in `nums` such that a + b + c + d = target? Find all
 * unique quadruplets in the array which gives the sum of `target`.
 *
 * Note:
 * The solution set must not contain duplicate quadruplets.
 */ 
#include <iostream>
#include <vector>
#include <set>

#include <algorithm>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> ans;
			set<vector<int>> t_ans;
			if (nums.size() < 4)
				return ans;

			sort(nums.begin(), nums.end());
			int tmp, size, tgt;
			int a, z;
			size = nums.size();
			int k = 0;

			while (k < size - 1 && nums[k] == nums[k + 1]) {
				++k;
			}
			k = (((k - 3) > 0) ? (k - 3) : 0);
			for (int i = k; i < size - 3; ++i){
				tmp = nums[i] - target;

				k = i + 1;
				while (k < size - 1 && nums[k] == nums[k + 1]) {
					++k;
				}
				k = (((k - 2) > i + 1) ? (k - 2) : (i + 1));
				for (int j = k; j < size - 2; ++j){
					tgt = tmp + nums[j];
					
					a = j + 1;
					while (a < size - 1 && nums[a] == nums[a + 1]){
						++a;
					}
					a = (a > (j + 1)) ? (a - 1) : j + 1;
					z = size - 1;
					while (a < z) {
						if (tgt + nums[a] + nums[z] < 0) {
							++a;
						} 

						else if (tgt + nums[a] + nums[z] == 0) {
							vector<int> add{nums[i], nums[j], nums[a], nums[z]};
							//ans.push_back(add);
							t_ans.insert(add);
							++a;
							--z;
						} 

						else if (tgt + nums[a] + nums[z] > 0) {
							--z;
						}
					}
				}
			}
			for (auto& x : t_ans){
				ans.push_back(x);
			}
			return ans;
		}
};

int main(int argc, char *args[]) {
	vector<int> a{1, 0, -1, 0, -2, 2};
	int a_tgt = 0;

	vector<int> b{-3, -2, -1, 0, 0, 1, 2, 3};
	int b_tgt = 0;

	vector<vector<int>> a_ans = Solution::fourSum(a, a_tgt);
	for (auto& x : a_ans){
		for (int i = 0; i < x.size(); ++i){
			cout << x[i] << " ";
		}
		cout << endl;
	}

	cout << endl;
	vector<vector<int>> b_ans = Solution::fourSum(b, b_tgt);
	for (auto& x : b_ans){
		for (int i = 0; i < x.size(); ++i){
			cout << x[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
