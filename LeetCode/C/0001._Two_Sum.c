int* twoSum(int* nums, int numsSize, int target){
    int min, max;
    min = max = nums[0];
    for (int i = 1; i < numsSize; ++i){
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
    }

    int* hash = (int*) calloc((max - min + 1), sizeof(int));
    int* ptrReturn = (int*) malloc(2 * sizeof(int));
    int find;
    for (int i = 0; i < numsSize; ++i){
        find = target - nums[i];
        if (find < min || find > max) continue;
        find -= min;
        if (hash[find] > 0){
            ptrReturn[0] = hash[find] - 1;
            ptrReturn[1] = i;
            break;
        }
        hash[nums[i] - min] = i + 1;
    }
    free(hash);
    return ptrReturn;
} // Using Hash Table.

int cmpfunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int* twoSum_pre1(int* nums, int numsSize, int target){
    int arrayIntIndex[numsSize];
    for (int i = 0; i < numsSize; ++i) arrayIntIndex[i] = nums[i];

    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int startIndex = 0, endIndex = numsSize - 1;
    while (startIndex < endIndex){
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
} // Step 1: Sort, Step 2: Setting Windows.
