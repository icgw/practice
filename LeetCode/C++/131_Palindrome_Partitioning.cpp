/* Given a string s, partition s such that every substring of the partition is a
 * palindrome.
 * Return all possible palindrome partitioning of s.
 * Exampe:
 * 	Input: "aab"
 * 	Output:
 * 	[
 * 		["aa", "b"],
 * 		["a", "a", "b"]
 * 	]
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<vector<string>> partition(string s){
			int n = s.size();
			vector<vector<string>> ans;
			vector<string> curr;
			partition(ans, curr, s);
			return ans;
		}

		static void partition(vector<vector<string>>& pat,
				vector<string>& curr, string s){
			int n = s.size();
			string sub;
			for (int i = 1; i < n; ++i){
				sub = s.substr(0, i);
				if (isPalindrom(sub)){
					curr.push_back(sub);
					partition(pat, curr, s.substr(i, n - i));
					curr.pop_back();
				}
			}
			if (isPalindrom(s)){
				curr.push_back(s);
				pat.push_back(curr);
				curr.pop_back();
				return ;
			}
		}

		static bool isPalindrom(string& s){
			int left = 0, right = s.size() - 1;
			while (left < right){
				if (s[left] != s[right]) return false;
				++left;
				--right;
			}
			return true;
		}
};

int main(int argc, char* argv[]){
	string str1 = "aab";
	vector<vector<string>> ans1 = Solution::partition(str1);
	for (auto& x : ans1){
		for (auto& y : x){
			cout << y << " ";
		}
		cout << endl;
	}

	return 0;
}
