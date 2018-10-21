/* Given a string, determine if it is a plindrome, considering only alphanumeric
 * characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid 
 * palindrome.
 *
 * Example:
 * 	Input: "A man, a plan, a canal: Panama"
 * 	Output: true
 */ 
#include <iostream>

using namespace std;

class Solution {
	public:
		static bool isPalindrome(string s){
			if (s.empty()) return true;
			int left = 0, right = s.size() - 1;
			while (left < right){
				if (!isAlphaNumber(s[left]))
					++left;
				else if (!isAlphaNumber(s[right]))
					--right;
				else if ((s[left] + 32 - 'a') % 32 
						!= (s[right] + 32 - 'a') % 32)
					return false;
				else {
					++left; --right;
				}
			}
			return true;
		}

		static bool isAlphaNumber(char ch){
			if (ch >= 'A' && ch <= 'Z')
				return true;
			else if (ch >= 'a' && ch <= 'z')
				return true;
			else if (ch >= '0' && ch <= '9')
				return true;
			return false;
		}
};

int main(int argc, char* argv[]){
	string str1 = "A man, a plan, a canal: Panama";
	string str2 = "race a car";

	cout << Solution::isPalindrome(str1) << endl;
	cout << Solution::isPalindrome(str2) << endl;

	return 0;
}
