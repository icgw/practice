#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::max;

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n){
            unordered_map<char, int> m;
            int max_count = 0;
            for (auto c : tasks){
                ++m[c];
                max_count = max(max_count, m[c]);
            }

            int ret = (max_count - 1) * (n + 1);
            for (auto &x : m)
                if (x.second == max_count) ++ret;
            return max(ret, (int) tasks.size());
        }
};
