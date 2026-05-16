#include "leetcode.h"

#include <stdio.h>

int *twoSum( int *nums, int numsSize, int target, int *returnSize );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int size = 0;

		int *arr = lc_parse_array( lineBuff, &size );

		if ( !fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
			break;
		}

		int target = 0;
		sscanf( lineBuff, "%d", &target );
		int	 returnSize = 0;
		int *result		= twoSum( arr, size, target, &returnSize );
		lc_print_array( result, returnSize );
	}
	return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *twoSum( int *nums, int numsSize, int target, int *returnSize ) {
	int *result = ( int * )malloc( 2 * sizeof( int ) );

	for ( int i = 0; i < numsSize; i++ ) {
		int k = target - nums[i];
		for ( int j = i + 1; j < numsSize; j++ ) {
			if ( nums[j] == k ) {
				result[0]	= i;
				result[1]	= j;
				*returnSize = 2;
				return result;
			}
		}
	}
	*returnSize = 0;
	return result;
}
