#include "leetcode.h"

#include <stdio.h>
#include <stdlib.h>

int *findDiagonalOrder( int **mat, int matSize, int *matColSize, int *returnSize );

int main( void ) {
	char lineBuff[256];
	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i			 = strcspn( lineBuff, "\n" );
		lineBuff[i]		 = '\0';
		int	  qttRows	 = 0, *qttCols;
		int **mat		 = lc_parse_matrix( lineBuff, &qttRows, &qttCols );
		int	  returnSize = 0;
		int	 *r			 = findDiagonalOrder( mat, qttRows, qttCols, &returnSize );

		lc_print_array( r, returnSize );
	}

	return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDiagonalOrder( int **mat, int matSize, int *matColSize, int *returnSize ) {
	int lenList = matSize * matColSize[0];
	*returnSize = lenList;

	int *array = ( int * )malloc( sizeof( int ) * lenList );
	int	 x = 0, y = 0;
	char dir = 'u';

	for ( int i = 0; i < lenList; i++ ) {
		array[i] = mat[x][y];

		if ( dir == 'u' ) {
			if ( x == 0 ) {
				if ( y + 1 < matColSize[0] ) {
					y += 1;
				} else {
					x += 1;
				}

				dir = 'd';
			} else {
				if ( y + 1 < matColSize[0] ) {
					y += 1;
					x -= 1;
				} else {
					x += 1;
					dir = 'd';
				}
			}
		} else {
			if ( y == 0 ) {
				if ( x + 1 < matSize ) {
					x += 1;
				} else {
					y += 1;
				}

				dir = 'u';
			} else {
				if ( x + 1 < matSize ) {
					x += 1;
					y -= 1;
				} else {
					y += 1;
					dir = 'u';
				}
			}
		}
	}

	return array;
}
