#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            unordered_map<int, int> m;
            int n = nums.size();
            for (int i = 0; i < n; ++i){
                if (m.count(nums[i]) > 0) return {m[nums[i]], i};
                m[target - nums[i]] = i;
            }
            return {};
        }
};
