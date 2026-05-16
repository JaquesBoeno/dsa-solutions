#include "leetcode.h"

#include <stdio.h>

char **fizzBuzz( int n, int *returnSize );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';
		int x		= 0;

		sscanf( lineBuff, "%d", &x );

		int	   rs = 0;
		char **r  = fizzBuzz( x, &rs );

		printf( "[" );
		for ( int j = 0; j < rs; j += 1 ) {
			printf( "\"%s\"", r[j] );
			if ( j < rs - 1 ) {
				printf( "," );
			}
		}
		printf( "]\n" );
	}

	return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz( int n, int *returnSize ) {
	char **r = ( char ** )malloc( n * sizeof( char * ) );

	for ( int i = 0; i < n; i++ ) {
		bool d3 = !( ( i + 1 ) % 3 ), d5 = !( ( i + 1 ) % 5 );

		if ( d3 && d5 ) {
			r[i] = ( char * )malloc( 9 * sizeof( char ) );
			strcpy( r[i], "FizzBuzz" );
		} else if ( d3 ) {
			r[i] = ( char * )malloc( 5 * sizeof( char ) );
			strcpy( r[i], "Fizz" );
		} else if ( d5 ) {
			r[i] = ( char * )malloc( 5 * sizeof( char ) );
			strcpy( r[i], "Buzz" );
		} else {
			r[i] = ( char * )malloc( 6 * sizeof( char ) );
			char tmp[6];
			sprintf( tmp, "%d", i + 1 );
			strcpy( r[i], tmp );
		}
	}

	*returnSize = n;
	return r;
}
