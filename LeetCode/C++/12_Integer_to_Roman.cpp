/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 * Symbol	Value
 * I        1
 * V        5
 * X        10
 * L        50
 * C        100
 * D        500
 * M        1000
 */ 
#include <iostream>
using namespace std;

class Solution {
	public:
		static string intToRoman(int num){
			string ans;

			int romanUnit[] = {1000, 500, 100, 50, 10, 5, 1};
			char charUnit[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
			int tmp = num, r;

			int s = tmp / 1000;
			if (s != 0){
				tmp = tmp % 1000;
				for (int i = 0; i < s; ++i)
					ans.push_back(charUnit[0]);
			}

			for (int i = 1; i < 6; i += 2){
				r = tmp / romanUnit[i + 1] - 5;
				if (r == -5)
					continue;

				if (r < -1){
					for (int k = 0; k < 5 + r; ++k)
						ans.push_back(charUnit[i + 1]);
				}
				
				if (r == -1){
					ans.push_back(charUnit[i + 1]);
					ans.push_back(charUnit[i]);
				}

				if (r == 0)
					ans.push_back(charUnit[i]);

				if (r > 0 && r < 4){
					ans.push_back(charUnit[i]);
					for (int k = 0; k < r; ++k)
						ans.push_back(charUnit[i + 1]);
				}

				if (r == 4){
					ans.push_back(charUnit[i + 1]);
					ans.push_back(charUnit[i - 1]);
				}
				tmp = tmp % romanUnit[i + 1];
			}
			return ans;
		}
};

int main(int argc, char *args[]) {

	int z = 3;
	int a = 4;
	int b = 9;
	int c = 58;
	int d = 1994;

	cout << Solution::intToRoman(z) << endl;
	cout << Solution::intToRoman(a) << endl;
	cout << Solution::intToRoman(b) << endl;
	cout << Solution::intToRoman(c) << endl;
	cout << Solution::intToRoman(d) << endl;

	return 0;
}
