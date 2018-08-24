/* Given an array `nums` of n integers, are there elements a, b, c in `nums`
 * such that a + b + c = 0? Find all unique triplets in the array which gives
 * the sum of zero.
 *
 * Note:
 * The solution set must not contain duplicate triplets.
 */ 
#include <iostream>
#include <vector>
#include <set>

#include <algorithm>

using namespace std;

class Solution {
	public:
		// Time Limit Exceeded.
		//static vector<vector<int>> threeSum(vector<int>& nums) {
			//vector<vector<int>> ans;
			//set<vector<int>> s_ans;
			//sort(nums.begin(), nums.end()); // low --> high
			//int tmp;
			//int a, b;
			//for (int i = 0; i < nums.size(); ++i){
				//a = nums[i];
				//for (int j = i + 1; j < nums.size(); ++j){
					//b = nums[j];
					//tmp = a + b;
					//for (int k = j + 1; k < nums.size(); ++k){
						//if (nums[k] == -tmp){
							//vector<int> curr;
							//curr.push_back(a);
							//curr.push_back(b);
							//curr.push_back(nums[k]);

							//s_ans.insert(curr);
							//break;
						//}
					//}
				//}
			//}
			//for (auto& x : s_ans){
				//ans.push_back(x);
			//}
			
			//return ans;
		//}
		
		static vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> ans;
			set<vector<int>> s_ans;
			sort(nums.begin(), nums.end()); // low --> high
			int s_nums = nums.size();
			if (s_nums > 2 && nums[0] == nums[s_nums - 1]){
				if (nums[0] == 0){
					vector<int> c;
					c.push_back(0);
					c.push_back(0);
					c.push_back(0);
					ans.push_back(c);
					return ans;
				} else {
					return ans;
				}
			}
			int tmp;
			int a, b;
			for (int i = 0; i < nums.size(); ++i){
				a = nums[i];
				for (int j = i + 1; j < nums.size(); ++j){
					b = nums[j];
					tmp = a + b;
					if (binary_search(nums.begin() + j + 1, nums.end(), -tmp)){
						vector<int> curr;
						curr.push_back(a);
						curr.push_back(b);
						curr.push_back(-tmp);

						s_ans.insert(curr);
					}
				}
			}

			for (auto& x : s_ans){
				ans.push_back(x);
			}
			
			return ans;
		}
};

int main(int argc, char *args[]) {
	int a[] = {-1, 0, 1, 2, -1, -4};
	int b[] = {0, 0, 0};
	int c[] = {-2, 0, 1, 1, 2};
	vector<int> aa(a, a + 6);
	vector<int> bb(b, b + 3);
	vector<int> cc(c, c + 5);

	vector<vector<int> > ans = Solution::threeSum(aa);
	for (auto& x : ans){
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
	}

	cout << endl;
	vector<vector<int> > b_ans = Solution::threeSum(bb);
	for (auto& x : b_ans){
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
	}

	cout << endl;
	vector<vector<int> > c_ans = Solution::threeSum(cc);
	for (auto& x : c_ans){
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
	}

	return 0;
}
