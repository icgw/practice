#include <vector>
using std::vector;

#include <cstdlib>
#include <algorithm>
using std::swap;

class Solution {
    private:
        vector<int> nums;

    public:
        Solution(vector<int> nums) {
            this->nums = nums;
        }

        vector<int> reset() {
            return this->nums;
        }

        vector<int> shuffle() {
            vector<int> ret(this->nums);
            for (int i = nums.size() - 1; i >= 0; --i) {
                swap(ret[i], ret[rand() % (i + 1)]);
            }
            return ret;
        }
};
