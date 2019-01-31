/* Given an array of strings, group anagrams together.
 *
 * Example:
 * 	Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 	Output:
 * 	[
 * 		["ate", "eat", "tea"],
 * 		["nat", "tan"],
 * 		["bat"]
 * 	]
 * Note:
 * 	+ All inputs will be in lowercase.
 * 	+ The order of your output does not matter.
 */ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
		static vector<vector<string>> groupAnagrams(vector<string>& strs){
			vector<vector<string>> ans;

			map<string, vector<string>> m;
			string tmp;
			for (auto& s : strs){
				tmp = s;
				sort(tmp.begin(), tmp.end());
				m[tmp].push_back(s);
			}

			for (auto& x : m){
				ans.push_back(x.second);
			}

			return ans;
		}
};

int main(int argc, char* args[]){
	string a[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> aa(a, a + 6);
	vector<vector<string>> a_ans = Solution::groupAnagrams(aa);
	for (auto& x : a_ans){
		for (auto& xx : x){
			cout << xx << " "; 
		}
		cout << endl;
	}

	return 0;
}
