/* Evaluate the value of an arithmeic expression in Reverse Polish Notation.
 */ 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
	public:
		 static int evalRPN(vector<string>& tokens){
			 stack<int> stk;
			 int n = tokens.size();
			 int a, b;
			 for (int i = 0; i < n; ++i){
				 int s = isOperand(tokens[i]);
				 if (s == 0){
					 stk.push(stoi(tokens[i]));
					 continue;
				 }
				 a = stk.top(); stk.pop();
				 b = stk.top(); stk.pop();
				 switch(s){
					 case 1:
						 stk.push(b + a);
						 break;
					 case 2:
						 stk.push(b - a);
						 break;
					 case 3:
						 stk.push(b * a);
						 break;
					 case 4:
						 stk.push(b / a);
						 break;
				 }
			 }
			 return stk.top();
		 }

		 static int isOperand(string str){
			 if (str.size() != 1) return 0; // number
			 if (str[0] == '+') return 1;
			 else if (str[0] == '-') return 2;
			 else if (str[0] == '*') return 3;
			 else if (str[0] == '/') return 4;
			 return 0;
		 }
};

int main(int argc, char *argv[]){
	vector<string> RPN {"4", "13", "5", "/", "+"};
	cout << Solution::evalRPN(RPN) << endl;

	return 0;
}
