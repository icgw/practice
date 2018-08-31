/* Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 */ 
#include <iostream>
#include <vector>

#include <stack>

using namespace std;

class Solution {
	public:
		static vector<string> generateParenthesis(int n) {
			vector<string> ans;
			if (n == 1){
				ans.push_back("()");
				return ans;
			}
			stack<char> l, r;
			for (int i = 0; i < n; ++i){
				l.push('(');
				r.push(')');
			}
			dfs(ans, "", l, r);

			return ans;
		}

		static void dfs(vector<string>& in, string str, 
				stack<char> left,
				stack<char> right){

			if (left.empty()){
				while (!right.empty()){
					str.push_back(right.top());
					right.pop();
				}
				in.push_back(str);
				return;
			}

			if (left.size() == right.size()){
				str.push_back(left.top());
				left.pop();
				dfs(in, str, left, right);
				return;
			}

			left.pop();
			dfs(in, str + "(", left, right);
			left.push('(');
			right.pop();
			dfs(in, str + ")", left, right);
		}
};

int main(int argc, char *args[]){
	int n = 4;

	vector<string> ans = Solution::generateParenthesis(n);
	for (auto& x : ans){
		cout << x << endl;
	}

	return 0;
}
