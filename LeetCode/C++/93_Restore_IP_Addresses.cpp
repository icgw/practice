/* Given a string containing only digits, restore it by returning all possible 
 * valid IP address combinations.
 *
 * Example:
 * 	Input: "25525511135"
 * 	Output: ["255.255.11.135", "255.255.111.35"]
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<string> restoreIPAddresses(string s){
			vector<string> ans;
			if (s.size() < 4) return ans;
			restore(s, ans, 4, "");
			return ans;
		}

		static void restore(string s, vector<string>& ans, int k, string ip){
			if (k == 0){
				if (s.empty()){
					ans.push_back(ip);
					return ;
				} else
					return ;
			}

			for (int i = 1; i <= 3; ++i){
				if (s.size() < i) break;
				string num = s.substr(0, i);
				if (isValid(num)){
					if (k == 1) restore(s.substr(i), ans, k - 1, ip + num);
					else restore(s.substr(i), ans, k - 1, ip + num + ".");
				}
			}
		}

		static bool isValid(string s){
			if (s.empty() || s.size() > 3 ||
					(s.size() > 1 && s[0] == '0')) return false;
			int num = stoi(s);
			return (num >= 0 && num <= 255);
		}
};

int main(int argc, char* args[]){
	string s = "25525511135";
	vector<string> ans = Solution::restoreIPAddresses(s);
	for (auto& x : ans){
		cout << x << endl;
	}

	return 0;
}
