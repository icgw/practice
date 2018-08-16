#include <iostream>
using namespace std;

class Solution {
	public:
		static string convert(string s, int numRows){
			if (numRows == 1)
				return s;
			string *ans = new string[numRows];
			string a = "";
			int r, j;
			for (int i = 0; i < s.size(); ++i){
				r = i % ((numRows - 1) << 1);
				j = (r < numRows) ? r : (numRows - 2 - (r % numRows));
				ans[j].append(1, s[i]);
			}
			for (int k = 0; k < numRows; ++k){
				a.append(ans[k]);
			}
			return a;
		}
};

int main (int argc, char *args[]){
	string s = "PAYPALISHIRING";
	int n1 = 3;
	int n2 = 4;
	string a = "A";
	int an = 1;
	
	cout << Solution::convert(s, n1) << endl;
	cout << Solution::convert(s, n2) << endl;
	cout << Solution::convert(a, an) << endl;

	return 0;
}


