#include <vector>
using std::vector;

#include <utility>
using std::pair;
using std::make_pair;

#include <queue>
using std::priority_queue;

class Solution {
    using int2pair = pair<int, pair<int, int>>;

    struct cmp {
        bool operator () (const int2pair &a,
                          const int2pair &b) {
            return a.first > b.first;
        }
    };

    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int m = matrix.size(); if (m == 0) return -1;
            int n = matrix[0].size();

            priority_queue<int2pair, vector<int2pair>, cmp> pq;
            for (int i = 0; i < n; ++i) pq.push(make_pair(matrix[i][0], make_pair(i, 0)));

            int ans;
            while (k--) {
                int e = pq.top().first; ans = e;
                int i = pq.top().second.first;
                int j = pq.top().second.second;
                pq.pop();
                if (j != n - 1) pq.push(make_pair(matrix[i][j + 1], make_pair(i, j + 1)));
            }
            return ans;
        }
};
