#include "leetcode.h"

#include <stdio.h>
#include <string.h>

int reverseDegree( char *s );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';

		int n = reverseDegree( lineBuff );
		printf( "%d\n", n );
	}

	return 0;
}

int reverseDegree( char *s ) {
	int sum = 0;

	for ( int i = 0; s[i] != '\0'; i++ ) {
		sum += ( 26 - ( s[i] - 97 ) ) * ( i + 1 );
	}

	return sum;
}
