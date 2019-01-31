#include <vector>
using std::vector;
using std::string;

using std::reverse;

class Solution {
    public:
        vector<string> removeInvalidParentheses(string s) {
            vector<string> ret;
            remove(s, ret, 0, 0, '(', ')');
            return ret;
        }
    private:
        void remove(string s, vector<string> &ans, 
                    int last_i, int last_j, const char open, const char close) {
            for (int stk = 0, i = last_i; i < s.size(); ++i) {
                if (s[i] == open)  stk++;
                if (s[i] == close) stk--;
                if (stk >= 0) continue;
                for (int j = last_j; j <= i; ++j) {
                    if (s[j] == close && (j == last_j || s[j - 1] != close)) {
                        remove(s.substr(0, j) + s.substr(j + 1), ans,
                               i, j, open, close);
                    }
                }
                return ;
            }

            if (open == '(') {
                reverse(s.begin(), s.end());
                remove(s, ans, 0, 0, close, open);
            }
            else {
                reverse(s.begin(), s.end());
                ans.push_back(s);
            }
        }
};
