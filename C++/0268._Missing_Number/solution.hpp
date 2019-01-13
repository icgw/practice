#include <vector>
using std::vector;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int ret = 0;
            for (int i = 0; i < nums.size(); ++i)
                ret += (nums[i] - i - 1);
            return -ret;
        }
};
