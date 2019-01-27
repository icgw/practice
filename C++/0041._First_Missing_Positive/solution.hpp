#include <vector>
using std::vector;

using std::swap;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                    swap(nums[i], nums[nums[i] - 1]);
            }
            for (int i = 0; i < n; ++i) {
                if (nums[i] != i + 1) return i + 1;
            }
            return n + 1;
        }
        /*************************************************************
        int partition(vector<int> &nums) {
            int p = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > 0) {
                    swap(nums[i], nums[p]);
                    p++;
                }
            }
            return p;
        }

        int firstMissingPositive(vector<int>& nums) {
            int k = partition(nums);
            int first_missing_index = k;
            for (int i = 0; i < k; ++i) {
                int tmp = nums[i] < 0 ? -nums[i] : nums[i];
                tmp = tmp - 1;
                if (tmp < k && nums[tmp] > 0) nums[tmp] = -nums[tmp];
            }

            for (int i = 0; i < k; ++i) {
                if (nums[i] > 0) {
                    first_missing_index = i;
                    break;
                }
            }
            return first_missing_index + 1;
        }
         ************************************************************/
};
