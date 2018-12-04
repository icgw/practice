#include <vector>
using std::vector;

class Solution {
    public:
        int findDuplicate(vector<int>& nums){
            if (nums.size() > 0){
                int slow, fast;
                slow = nums[0];
                fast = nums[nums[0]];
                while (fast != slow){
                    slow = nums[slow];
                    fast = nums[nums[fast]];
                }
                fast = 0;
                while (fast != slow){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
            return -1;
        }
};
