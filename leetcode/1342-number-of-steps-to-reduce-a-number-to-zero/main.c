#include "leetcode.h"

#include <stdio.h>
#include <string.h>

int numberOfSteps( int num );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';

		int n = 0;
		sscanf( lineBuff, "%d", &n );

		printf( "%d\n", numberOfSteps( n ) );
	}

	return 0;
}

int numberOfSteps( int num ) {
	int steps = 0;
	while ( num ) {
		steps += 1;
		if ( num % 2 == 0 )
			num /= 2;
		else
			num -= 1;
	}

	return steps;
}
