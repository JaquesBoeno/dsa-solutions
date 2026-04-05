/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
	int* rs = (int*)malloc(numsSize * sizeof(int));
	int	 s	= 0;

	*returnSize = numsSize;
	for (int i = 0; i < numsSize; i++) {
		s += nums[i];
		rs[i] = s;
	}

	return rs;
}
