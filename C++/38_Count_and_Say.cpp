/* The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 	1. 1
 * 	2. 11
 * 	3. 21
 * 	4. 1211
 * 	5. 111221
 *
 * 	`1` is read off as "one 1" or `11`.
 * 	`11` is read off as "two 1s" or `21`.
 * 	`21` is read off as "one 2, then one 1", or `1211`.
 *
 * 	Given an integer n, generate the n^{th} term of the count-and-say sequence.
 *
 * 	Note: Each term of the sequence of integers will be represented as a string.
 */ 
#include <iostream>

using namespace std;

class Solution {
	public:
		static string countAndSay(int n){
			string pre_ans, ans = "1";
			int count = 0;
			char pre_ch;
			int j;
			for (int i = 1; i < n; ++i){
				pre_ans = ans;
				ans.clear();

				pre_ch = pre_ans[0];
				j = count = 1;
				if (pre_ans.size() == 1){
					ans.push_back('1');
					ans.push_back(pre_ans[0]);
					continue;
				}
				while (j < pre_ans.size()){
					if (pre_ans[j] == pre_ch){
						++count;
					} else {
						ans.push_back('0' + count);
						ans.push_back(pre_ch);
						pre_ch = pre_ans[j];
						count = 1;
					}
					if (j == pre_ans.size() - 1){
						ans.push_back('0' + count);
						ans.push_back(pre_ans[j]);
					}
					++j;
				}
			}
			return ans;
		}
};

int main(int argc, char* args[]){
	for (int i = 1; i < 6; ++i){
		cout << Solution::countAndSay(i) << endl;
	}
	return 0;
}
