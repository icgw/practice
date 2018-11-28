#!/usr/bin/env python3 

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n1, n2 = len(nums1), len(nums2)
        left, right = (n1 + n2 + 1) // 2, (n1 + n2 + 2) // 2
        return (self.findKthSortedArrays(nums1, 0, nums2, 0, left) + \
                self.findKthSortedArrays(nums1, 0, nums2, 0, right)) / 2

    def findKthSortedArrays(self, nums1, s1, nums2, s2, k):
        """
        :type nums1: List[int]
        :type s1: int
        :type nums2: List[int]
        :type s2: int
        :type k: int
        :rtype: float
        """
        if s1 >= len(nums1):
            return nums2[s2 + k - 1]
        if s2 >= len(nums2):
            return nums1[s1 + k - 1]
        if k == 1:
            return min(nums1[s1], nums2[s2]) 
        p = k // 2
        v1 = nums1[s1 + p - 1] if s1 + p - 1 < len(nums1) else float("inf")
        v2 = nums2[s2 + p - 1] if s2 + p - 1 < len(nums2) else float("inf")
        return self.findKthSortedArrays(nums1, s1 + p, nums2, s2, k - p) if v1 < v2 \
                else self.findKthSortedArrays(nums1, s1, nums2, s2 + p, k - p)
if __name__ == "__main__":
    nums1, nums2 = [1, 3], [2]
    print(Solution().findMedianSortedArrays(nums1, nums2))
    nums1, nums2 = [1, 2], [3, 4]
    print(Solution().findMedianSortedArrays(nums1, nums2))
