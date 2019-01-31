#include <sstream>
using std::istringstream;
using std::string;

class Solution {
    public:
        int calculate(string s) {
            istringstream iss("+" + s + "+");
            char op;
            long long term = 0, ret = 0;
            while (iss >> op) {
                if (op == '+' || op == '-') {
                    ret += term;
                    iss >> term;
                    term *= (op == '+') ? 1 : -1;
                } else {
                    int n; iss >> n;
                    if (op == '*') term *= n;
                    if (op == '/') term /= n;
                }
            }
            return ret;
        }
};
