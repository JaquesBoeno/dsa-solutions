#include "leetcode.h"

#include <stdio.h>

int searchInsert( int *nums, int numsSize, int target );

int main( ) {
	char line_arr[256];
	char line_num[64];

	while ( fgets( line_arr, sizeof( line_arr ), stdin ) != NULL ) {
		if ( fgets( line_num, sizeof( line_num ), stdin ) == NULL ) {
			break;
		}

		int	 size;
		int *arr = lc_parse_array( line_arr, &size );

		int target;
		sscanf( line_num, "%d", &target );

		int result = searchInsert( arr, size, target );
		printf( "%d\n", result );

		free( arr );
	}
	return 0;
}

int searchInsert( int *nums, int numsSize, int target ) {
	int i = numsSize / 2, l = 0, r = numsSize, lowerNear = -100000, c = 0;

	while ( l < r ) {
		c = nums[i];

		if ( c == target ) {
			return i;
		}

		if ( c == lowerNear ) {
			return i + 1;
		}

		if ( c < target ) {
			l = i;

			if ( c > lowerNear )
				lowerNear = c;
		} else {
			r = i;
		}
		i = ( r + l ) / 2;
	}

	return i;
}
