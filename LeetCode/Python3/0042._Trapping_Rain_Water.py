#!/usr/bin/env python3
class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        lo, hi, water, level = 0, len(height) - 1, 0, 0
        while lo < hi:
            if height[lo] < height[hi]:
                lower = height[lo]
                lo += 1
            else:
                lower = height[hi]
                hi -= 1
            level = max(level, lower)
            water += (level - lower)
        return water

if __name__ == "__main__":
    print(Solution().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
