#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k){
            unordered_map<int, int> freq;
            for (auto& x : nums) ++freq[x];
            vector<vector<int>> buckets(nums.size() + 1);
            for (auto& x : freq) buckets[x.second].push_back(x.first);

            vector<int> ret;
            for (int i = nums.size(); i > 0 && ret.size() < k; --i){
                if (buckets[i].size() == 0) continue;
                for (auto& x : buckets[i]) ret.push_back(x);
            }
            return ret;
        }
};
