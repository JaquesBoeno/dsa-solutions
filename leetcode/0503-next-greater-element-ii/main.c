#include "leetcode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *nextGreaterElements( int *nums, int numsSize, int *returnSize );

int main( ) {
	char lineBuff[256];
	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';
		int len		= 0;

		int *array		= lc_parse_array( lineBuff, &len );
		int	 returnSize = 0;
		int *result		= nextGreaterElements( array, len, &returnSize );
		lc_print_array( result, returnSize );
	}
	return 0;
}

int *nextGreaterElements( int *nums, int numsSize, int *returnSize ) {
	int *result = ( int * )malloc( sizeof( int ) * numsSize );
	*returnSize = numsSize;

	for ( int i = 0; i < numsSize; i += 1 ) {
		result[i] = -1;

		for ( int j = i; j < numsSize + i; j += 1 ) {
			int vj = nums[j % numsSize];

			if ( vj > nums[i] ) {
				result[i] = vj;
				break;
			}
		}
	}

	return result;
}
