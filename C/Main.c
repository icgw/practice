#include <stdio.h>
#include <stdlib.h>

#define ID 1
#define SOLUTION() Solution##ID()

#if ID == 1
#include "0001._Two_Sum.c"
#define RUN_EXAMPLE Solution1();
#endif

#if ID == 1
void Solution1(){
	// 1. Two Sum
	int numsSize = 4, target = 9;
	int nums[4] = {2, 7, 11, 15};
	int *ans = twoSum(nums, numsSize, target);
	printf(" Input: nums = [%d, %d, %d, %d], target = %d\n", 
			nums[0], nums[1], nums[2], nums[3], target);
	printf("Output: [%d, %d]\n", ans[0], ans[1]);
	free(ans);
}
#endif

int main(int argc, char *argv[]){
	RUN_EXAMPLE
	return 0;
}
