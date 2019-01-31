#include <vector>
using std::vector;

using std::string;
#include <unordered_set>
using std::unordered_set;

class Solution {
    public:
        int numUniqueEmails(vector<string>& emails) {
            unordered_set<string> unique;
            for (auto &e : emails) {
                auto pivot = e.find_first_of('@'); auto name = e.substr(0, pivot), domain = e.substr(pivot);
                name.erase(remove(name.begin(), name.end(), '.'), name.end());
                unique.insert(name.erase(name.find_first_of('+')) + domain);
            }
            return static_cast<int>(unique.size());
        }
};
