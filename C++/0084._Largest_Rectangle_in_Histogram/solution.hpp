#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> ascend;
            int maxArea = 0;
            for (int i = 0; i <= heights.size(); ++i) {
                while (!ascend.empty() &&
                        (i == heights.size() || heights[ascend.top()] >= heights[i])){
                    int h = heights[ascend.top()];
                    ascend.pop();
                    int sidx = ascend.empty() ? -1 : ascend.top();
                    if (h * ((i - 1) - (sidx + 1) + 1) > maxArea)
                        maxArea = h * ((i - 1) - (sidx + 1) + 1);
                }
                ascend.push(i);
            }
            return maxArea;
        }
};
