#include <stdio.h>
#include <stdlib.h>

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

int main( void ) {
	int rows = 3, cols = 3;

	int **mat = malloc( rows * sizeof( int * ) );
	int	  tmp[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	for ( int i = 0; i < rows; i++ ) {
		mat[i] = malloc( cols * sizeof( int ) );
		for ( int j = 0; j < cols; j++ ) {
			mat[i][j] = tmp[i][j];
		}
	}

	int	 colSize[3] = { 3, 3, 3 }, returnSize = 0;
	int *result = findDiagonalOrder( mat, rows, colSize, &returnSize );

	for ( int i = 0; i < returnSize; i++ ) {
		printf( "%d ", result[i] );
	}

	printf( "\n" );

	free( result );
	for ( int i = 0; i < rows; i++ ) {
		free( mat[i] );
	}
	free( mat );

	return 0;
}
