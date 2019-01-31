#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;
using std::max;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            unordered_set<int> s(nums.begin(), nums.end());
            int ret = 1;
            for (auto n : nums) {
                if (s.count(n) == 0) continue;
                s.erase(n); // Note!!!
                int pre = n - 1, nxt = n + 1;
                while (s.count(pre)) s.erase(pre--); // Note!!!
                while (s.count(nxt)) s.erase(nxt++); // Note!!!
                ret = max(ret, nxt - pre - 1);
            }
            return ret;
        }
};
