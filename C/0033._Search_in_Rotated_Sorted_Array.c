int search(int* nums, int numsSize, int target){
    int lo = 0, hi = numsSize - 1, mid;
    while (lo < hi){
        mid = (lo + hi) / 2;
        if (nums[mid] < nums[hi]) hi = mid;
        else lo = mid + 1;
    }
    int start = lo, realMid;
    lo = 0, hi = numsSize - 1;
    while (lo <= hi){
        mid = (lo + hi) / 2;
        realMid = (mid + start) % numsSize;
        if (nums[realMid] == target) return realMid;
        if (nums[realMid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
