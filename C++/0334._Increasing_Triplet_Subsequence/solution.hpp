#include <vector>
using std::vector;
using std::min;

class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            if (nums.size() < 3) return false;
            int c1 = INT_MAX, c2 = INT_MAX;
            for (auto i : nums) {
                if (i <= c1)
                    c1 = i;
                else if (i <= c2)
                    c2 = i;
                else
                    return true;
            }
            return false;
        }
};
