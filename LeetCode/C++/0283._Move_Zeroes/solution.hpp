#include <vector>
using std::vector;
using std::swap;

class Solution {
    public:
        void moveZeroes(vector<int>& nums){
            for (int i = 0, j = 0, n = nums.size(); i < n; ++i)
                if (nums[i] != 0) swap(nums[j++], nums[i]);
        }
};
