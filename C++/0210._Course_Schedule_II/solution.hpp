#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

#include <utility>
using std::pair;

#include <stack>
using std::stack;

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<int> inDegree(numCourses, 0);
            unordered_map<int, unordered_set<int>> graph;
            for (auto &p : prerequisites) {
                graph[p.second].insert(p.first);
                inDegree[p.first]++;
            }

            stack<int> stk;
            vector<int> ret;
            for (int i = 0; i < numCourses; ++i)
                if (inDegree[i] == 0) {
                    stk.push(i);
                    ret.push_back(i);
                }

            while (!stk.empty()) {
                for (int sz = stk.size(); sz > 0; --sz) {
                    int tmp = stk.top(); stk.pop();
                    for (auto next : graph[tmp]) {
                        inDegree[next]--;
                        if (inDegree[next] == 0) {
                            stk.push(next);
                            ret.push_back(next);
                        }
                    }
                }
            }
            return ret.size() == numCourses ? ret : vector<int>{};
        }
};
