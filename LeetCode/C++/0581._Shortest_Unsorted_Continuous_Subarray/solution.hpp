#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums){
            int sz = nums.size();
            if (sz == 0) return 0;

            vector<int> minrhs(sz), maxlhs(sz);

            minrhs[sz - 1] = nums[sz - 1];
            for (int i = sz - 2; i >= 0; --i)
                minrhs[i] = min(nums[i], minrhs[i + 1]);

            maxlhs[0] = nums[0];
            for (int i = 1; i < sz; ++i)
                maxlhs[i] = max(nums[i], maxlhs[i - 1]);

            int lo = 0, hi = sz - 1;
            while (lo < sz && nums[lo] <= minrhs[lo]) ++lo;
            while (hi >= lo && nums[hi] >= maxlhs[hi]) --hi;

            return hi - lo + 1;
        }
};
