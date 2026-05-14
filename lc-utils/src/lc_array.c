#include "leetcode.h"

static int count_elements( const char *s ) {
	const char *p = strchr( s, '[' );
	if ( !p )
		return 0;
	p++;

	int n			= 0;
	int depth		= 0;
	int has_content = 0;

	while ( *p && !( *p == ']' && depth == 0 ) ) {
		if ( *p == '[' ) {
			depth++;
		} else if ( *p == ']' ) {
			depth--;
		} else if ( *p == ',' && depth == 0 ) {
			n++;
		} else if ( *p != ' ' ) {
			has_content = 1;
		}
		p++;
	}
	return has_content ? n + 1 : 0;
}

static void skip_ws( const char **p ) {
	while ( **p == ' ' || **p == '\t' ) {
		( *p )++;
	}
}

static int next_int( const char **p, int *out ) {
	skip_ws( p );
	char *end;
	long  v = strtol( *p, &end, 10 );

	if ( end == *p ) {
		return 0;
	}
	*out = ( int )v;
	*p	 = end;
	return 1;
}

int *lc_parse_array( const char *s, int *len ) {
	*len = 0;

	if ( !s ) {
		return NULL;
	}

	int cap = count_elements( s );
	if ( cap == 0 ) {
		return NULL;
	}

	int *arr = malloc( cap * sizeof( int ) );
	if ( !arr ) {
		return NULL;
	}

	const char *p = strchr( s, '[' );
	if ( !p ) {
		free( arr );
		return NULL;
	}
	p++; /* pula '[' */

	while ( *p && *p != ']' ) {
		skip_ws( &p );

		int v;

		if ( !next_int( &p, &v ) ) {
			break;
		}

		arr[( *len )++] = v;
		skip_ws( &p );

		if ( *p == ',' ) {
			p++;
		}
	}

	return arr;
}

// int **lc_parse_matrix( const char *s, int *rows, int *cols ) {}

void lc_free_matrix( int **m, int rows ) {
	if ( !m ) {
		return;
	}

	for ( int i = 0; i < rows; i++ ) {
		free( m[i] );
	}

	free( m );
}

void lc_print_array( const int *arr, int len ) {
	printf( "[" );
	printf( "%d", arr[0] );
	for ( int i = 1; i < len; i++ ) {
		printf( ",%d", arr[i] );
	}
	printf( "]\n" );
}

void lc_print_matrix( int **m, int rows, int cols ) {
	printf( "[\n" );
	for ( int i = 0; i < rows; i++ ) {
		printf( "\t" );
		lc_print_array( m[i], cols );
	}

	printf( "]\n" );
}
