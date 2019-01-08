#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> s;
            for (auto i : nums) {
                if (s.count(i)) return true;
                s.insert(i);
            }
            return false;
        }
};
