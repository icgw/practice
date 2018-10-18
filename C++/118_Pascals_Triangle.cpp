#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> generate(int numRows){
			vector<vector<int>> ans;
			if (numRows < 1) return ans;

			vector<int> pre(1, 1);
			ans.push_back(pre);

			int preSize;
			while (numRows > 1){
				preSize = pre.size();

				vector<int> add;
				add.push_back(1);
				for (int i = 1; i < preSize; ++i){
					add.push_back(pre[i - 1] + pre[i]);
				}
				add.push_back(1);

				ans.push_back(add);
				pre = add;
				--numRows;
			}
			return ans;
		}
};

int main(int argc, char* argv[]){
	int n = 5;
	vector<vector<int>> ans = Solution::generate(n);
	for (auto& x : ans){
		for (auto& y : x){
			cout << y << " ";
		}
		cout << endl;
	}
	
	return 0;
}
