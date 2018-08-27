/* Given a string containing just the characters '(', ')', '{', '}', '[' and 
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 * 	1. Open brackets must be closed by the same type of brackets.
 * 	2. Open brackets must be closed in the correct order.
 *
 * Note that an empty string is also considered valid.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static bool isValid(string s) {
			vector<char> s_stack;
			char curr;
			for (int i = 0; i < s.size(); ++i){
				curr = s[i];
				if (curr == '(' || curr == '[' || curr == '{') {
					s_stack.push_back(curr);
				} 
				else if (curr == ')') {
					if (s_stack.size() == 0 || s_stack.back() != '(')
						return false;
					s_stack.pop_back();
				}
				else if (curr == ']') {
					if (s_stack.size() == 0 || s_stack.back() != '[')
						return false;
					s_stack.pop_back();
				}
				else if (curr == '}') {
					if (s_stack.size() == 0 || s_stack.back() != '{')
						return false;
					s_stack.pop_back();
				}
			}
			return (s_stack.size() == 0);
		}
};

int main(int argc, char *args[]) {
	string a = "()";
	string b = "()[]{}";
	string c = "(]";
	string d = "([)]";
	string e = "{[]}";

	cout << Solution::isValid(a) << endl;
	cout << Solution::isValid(b) << endl;
	cout << Solution::isValid(c) << endl;
	cout << Solution::isValid(d) << endl;
	cout << Solution::isValid(e) << endl;

	return 0;
}
