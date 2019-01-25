#include <unordered_map>
using std::unordered_map;
using std::max;
using std::string;

class Solution {
    public:
        int longestSubstring(string s, int k) {
            unordered_map<char, int> m;
            for (auto ch : s) m[ch]++;
            int mid = 0, sz = s.size();

            while (mid < sz && m[s[mid]] >= k) mid++;
            if (mid == sz) return sz;

            int left = longestSubstring(s.substr(0, mid), k);
            while (mid < sz && m[s[mid]] < k) mid++;
            int right = longestSubstring(s.substr(mid), k);

            return max(left, right);
        }
};
