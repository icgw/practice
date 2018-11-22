int cmpfunc(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target){
	int arrayIntIndex[numsSize];
	for (int i = 0; i < numsSize; ++i) arrayIntIndex[i] = nums[i];

	qsort(nums, numsSize, sizeof(int), cmpfunc);

	int startIndex = 0, endIndex = numsSize - 1;
	while (1){
		if (nums[startIndex] + nums[endIndex] == target) break;
		if (nums[startIndex] + nums[endIndex] < target) ++startIndex;
		else --endIndex;
	}

	int *ptrReturn = (int*) malloc(2 * sizeof(int));
	for (int i = 0; i < numsSize; ++i){
		if (nums[startIndex] == arrayIntIndex[i]){
			ptrReturn[0] = i;
			break;
		}
	}
	for (int i = 0; i < numsSize; ++i){
		if (nums[endIndex] == arrayIntIndex[i] && ptrReturn[0] != i){
			ptrReturn[1] = i;
			break;
		}
	}
	return ptrReturn;
} // Step 1: Sort, Step 2: Skip Windows.
