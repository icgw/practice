#include <vector>
using std::vector;
using std::string;

class Solution {
    public:
        string minWindow(string s, string t) {
            vector<int> m(128, 0);
            for (auto c : t) ++m[c];
            int lo = 0, hi = 0, minD = INT_MAX, counter = t.size(), head;
            while (hi < s.size()) {
                if (m[s[hi++]]-- > 0) --counter;
                while (counter == 0) {
                    if (hi - lo < minD) minD = hi - (head = lo);
                    if (m[s[lo++]]++ == 0) ++counter;
                }
            }
            return minD == INT_MAX ? "" : s.substr(head, minD);
        }
};
