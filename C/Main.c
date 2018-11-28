#include <stdio.h>
#include <stdlib.h>

#define ID 33
#define SOLUTION() Solution##ID()

#if ID == 1
#include "0001._Two_Sum.c"
#define RUN_EXAMPLE Solution1();

void Solution1(){
	// 1. Two Sum
	int numsSize = 4, target = 9;
	int nums[4] = {2, 7, 11, 15};
	int *ans = twoSum(nums, numsSize, target);
	// int *ans = twoSum_V2(nums, numsSize, target); // using Hash Table.
	printf(" Input: nums = [%d, %d, %d, %d], target = %d\n", 
			nums[0], nums[1], nums[2], nums[3], target);
	printf("Output: [%d, %d]\n", ans[0], ans[1]);
	free(ans);
}
#endif

#if ID == 33
#include "0033._Search_in_Rotated_Sorted_Array.c"
#define RUN_EXAMPLE Solution33();

void Solution33(){
	// 33. Search in Rotated Sorted Array
	int nums[7] = {4, 5, 6, 7, 0, 1, 2};
	printf("Output: %d\n", search(nums, 7, 0));
	printf("Output: %d\n", search(nums, 7, 3));
}
#endif


int main(int argc, char *argv[]){
	RUN_EXAMPLE
	return 0;
}
