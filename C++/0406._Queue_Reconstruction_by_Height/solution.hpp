#include <vector>
using std::vector;
using std::pair;
using std::sort;

class Solution {
    public:
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people){
            const static auto cmp = [](const pair<int, int>& l, const pair<int, int>& r){
                return l.first > r.first || (l.first == r.first && l.second <= r.second);
            };
            sort(people.begin(), people.end(), cmp);
            vector<pair<int, int>> ret;
            for (auto p : people){
                ret.insert(ret.begin() + p.second, p);
            }
            return ret;
        }
};

