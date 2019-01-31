/* Given an input string, reverse the string word by word.
 *
 * Example:
 * 	Input: "the sky is blue",
 * 	Output: "blue is sky the".
 *
 * Note:
 * 	+ A word is defined as a sequence of non-space characters.
 * 	+ Input string may contain leading or trailing spaces. However, your 
 * 	  reversed string should not contain leading or trailing spaces.
 * 	+ You need to reduce multiple spaces between two words to a single space in 
 * 	  the reversed string.
 *
 * Follow up: For C programmers, try to solve it in-place in O(1) space.
 */
#include <iostream>

using namespace std;

class Solution {
	public:
		static void reverseWords(string &s){
			reverse(s.begin(), s.end());
			int currPos = 0, n = s.size(), i = 0, tmp;
			while (i < n){
				while (i < n && s[i] == ' ') ++i;
				if (currPos > 0 && i < n) s[currPos++] = ' ';
				tmp = currPos;
				while (i < n && s[i] != ' ') 
					s[currPos++] = s[i++];
				reverse(s.begin() + tmp, s.begin() + currPos);
			}
			s.resize(currPos);
		}
};

int main(int argc, char *argv[]){
	string s = "the sky is blue";
	cout << s << endl;
	Solution::reverseWords(s);
	cout << s << endl;
	return 0;
}
