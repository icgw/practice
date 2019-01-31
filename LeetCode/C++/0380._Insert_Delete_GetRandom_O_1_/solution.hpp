#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <cstdlib>

class RandomizedSet {
    private:
        vector<int> cnt;
        unordered_map<int, int> m;

    public:
        RandomizedSet() { }

        bool insert(int val) {
            if (m.find(val) != m.end()) return false;
            m[val] = cnt.size();
            cnt.emplace_back(val);
            return true;
        }

        bool remove(int val) {
            if (m.find(val) == m.end()) return false;
            int last = cnt.back();
            cnt[m[val]] = last;
            m[last] = m[val];
            m.erase(val);
            cnt.pop_back();
            return true;
        }

        int getRandom() {
            return cnt[rand() % cnt.size()];
        }
};
