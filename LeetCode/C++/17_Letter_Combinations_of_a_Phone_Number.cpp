/* Given a string containing digits from 2-9 inclusive, return all possible let-
 * ter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone butons) is given
 * below. Note that 1 does not map to any letters.
 */ 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		static string int2str(char i) {
			string ans;
			switch (i) {
				case '2':
					ans = "abc";
					break;
				case '3':
					ans = "def";
					break;
				case '4':
					ans = "ghi";
					break;
				case '5':
					ans = "jkl";
					break;
				case '6':
					ans = "mno";
					break;
				case '7':
					ans = "pqrs";
					break;
				case '8':
					ans = "tuv";
					break;
				case '9':
					ans = "wxyz";
					break;
			}
			return ans;
		}
		
		static vector<string> letterCombinations(string digits) {
			vector<string> ans;
			int size = digits.size();
			int *tmp = new int[size];
			vector<string> str_tmp;
			for (int i = 0; i < size; ++i){
				tmp[i] = 0;
				str_tmp.push_back(int2str(digits[i]));
			}

			string end = int2str(digits[size - 1]);
			int end_size = end.size();

			bool flag = true;
			while (tmp[size - 1] < end_size){
				string add;
				for (int i = 0; i < size; ++i){
					if (tmp[i] < str_tmp[i].size()){
						add.push_back(str_tmp[i][tmp[i]]);
					} else if (i == size - 1) {
						flag = false;
						break;
					} else {
						tmp[i] = 0;
						++(tmp[i + 1]);
						add.push_back(str_tmp[i][0]);
					}
				}
				if (flag){
					ans.push_back(add);
				}
				++(tmp[0]);
			}
			
			return ans;
		}
};

int main(int argc, char *args[]){
	string a = "23";

	vector<string> ans = Solution::letterCombinations(a);
	for (auto &x : ans){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
