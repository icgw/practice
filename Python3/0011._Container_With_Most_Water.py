#!/usr/bin/env python3
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area, lo, hi = 0, 0, len(height) - 1
        h = 0
        while lo < hi:
            area = max(area, min(height[lo], height[hi]) * (hi - lo))
            if height[lo] < height[hi]:
                lo += 1
            else:
                hi -= 1
        return area

if __name__ == "__main__":
    h = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    print(Solution().maxArea(h))
