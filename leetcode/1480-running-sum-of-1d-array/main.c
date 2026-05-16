#include "leetcode.h"

#include <stdio.h>
#include <string.h>

int *runningSum( int *nums, int numsSize, int *returnSize );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';

		int	 len		= 0;
		int *arr		= lc_parse_array( lineBuff, &len );
		int	 returnSize = 0;
		int *array		= runningSum( arr, len, &returnSize );

		lc_print_array( array, returnSize );
	}

	return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *runningSum( int *nums, int numsSize, int *returnSize ) {
	int *rs = ( int * )malloc( numsSize * sizeof( int ) );
	int	 s	= 0;

	*returnSize = numsSize;
	for ( int i = 0; i < numsSize; i++ ) {
		s += nums[i];
		rs[i] = s;
	}

	return rs;
}
