#include <vector>
using std::vector;

class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums){
            int id;
            for (auto &i : nums){
                id = i > 0 ? i - 1 : -i - 1;
                if (nums[id] > 0) nums[id] = -nums[id];
            }
            vector<int> ret;
            for (int i = 0, n = nums.size(); i < n; ++i)
                if (nums[i] > 0) ret.push_back(i + 1);
            return ret;
        }
};
