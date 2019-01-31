#include <vector>
using std::vector;
using std::string;

class Solution {
    public:
        int firstUniqChar(string s) {
            vector<int> m(26, 0);
            for (auto c : s) {
                m[c - 'a']++;
            }
            for (int i = 0; i < s.size(); ++i) {
                if (m[s[i] - 'a'] == 1) return i;
            }
            return -1;
        }
};
