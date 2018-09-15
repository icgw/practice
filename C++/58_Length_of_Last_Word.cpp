/* Given a string s consists of upper/lower-case alphabets and empty space 
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space 
 * characters only.
 *
 * Example:
 * 	Input: "Hello World"
 * 	Output: 5
 */ 
#include <iostream>

using namespace std;

class Solution {
	public:
		static int lengthOfLastWord(string s){
			if (s.size() == 0){
				return 0;
			}

			int i = s.size();
			while (s[--i] == ' ');

			int ans = 0;
			for ( ; i >= 0 && s[i] != ' '; --i){
				++ans;
			}

			return ans;
		}
};

int main(int argc, char* args[]){
	string a = "Hello World";
	cout << Solution::lengthOfLastWord(a) << endl;
	return 0;
}


