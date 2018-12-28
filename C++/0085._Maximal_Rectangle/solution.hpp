#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int ret = 0, row = matrix.size();
            if (row == 0) return ret;

            int column = matrix[0].size();
            vector<int> left(column, 0), right(column, column), height(column, 0);

            for (auto v : matrix) {
                for (int i = 0; i < column; ++i) {
                    if (v[i] == '1') 
                        height[i]++;
                    else
                        height[i] = 0;
                }

                int curr_left = 0;
                for (int i = 0; i < column; ++i) {
                    if (v[i] == '1')
                        left[i] = max(left[i], curr_left);
                    else {
                        left[i] = 0;
                        curr_left = i + 1;
                    }
                }

                int curr_right = column;
                for (int i = column - 1; i >= 0; --i) {
                    if (v[i] == '1')
                        right[i] = min(right[i], curr_right);
                    else {
                        right[i] = column;
                        curr_right = i;
                    }
                }

                for (int i = 0; i < column; ++i) {
                    ret = max(ret, (right[i] - left[i]) * height[i]);
                }
            }
            return ret;
        }
};
