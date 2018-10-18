#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<int> getRow(int rowIndex){
			if (rowIndex < 0) return {};

			vector<int> ans(rowIndex + 1, 1);
			for (int i = rowIndex - 1; i > 0; --i){
				for (int j = i + 1; j <= rowIndex; ++j){
					ans[j - 1] += ans[j];
				}
			}
			return ans;
		}
};

int main(int argc, char* argv[]){
	int n = 3;
	vector<int> ans = Solution::getRow(3);
	for (auto& x : ans){
		cout << x << " ";
	}
	cout << endl;
}
