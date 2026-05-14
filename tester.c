#include <stdio.h>
#include <string.h>

#define ANSI_RESET "\033[0m"
#define ANSI_GREEN "\033[32m"
#define ANSI_RED   "\033[31m"
#define ANSI_BOLD  "\033[1m"
#define ANSI_DIM   "\033[2m"

static void trim_newline( char *s ) {
	if ( !s )
		return;
	char *p = s;
	while ( *p ) {
		if ( *p == '\n' || *p == '\r' ) {
			*p = '\0';
			return;
		}
		p++;
	}
}

int main( int argc, char **argv ) {
	if ( argc != 3 ) {
		fprintf( stderr, "Uso: %s <expected.txt> <output.txt>\n", argv[0] );
		return 1;
	}

	const char *exp_path = argv[1];
	const char *out_path = argv[2];

	FILE *f_exp = fopen( exp_path, "r" );
	FILE *f_out = fopen( out_path, "r" );
	if ( !f_exp || !f_out ) {
		fprintf( stderr, "Erro abrindo '%s' ou '%s'\n", exp_path, out_path );
		return 1;
	}

	char buf_exp[512];
	char buf_out[512];
	int	 case_no = 1;
	int	 total	 = 0;
	int	 passed	 = 0;

	while ( 1 ) {
		char *line_exp = fgets( buf_exp, sizeof( buf_exp ), f_exp );
		char *line_out = fgets( buf_out, sizeof( buf_out ), f_out );

		if ( !line_exp && !line_out ) {
			break; // fim dos dois arquivos
		}

		total++;

		trim_newline( line_exp );
		trim_newline( line_out );

		int ok = 0;

		if ( line_exp && line_out && strcmp( buf_exp, buf_out ) == 0 ) {
			ok = 1;
		}

		printf(
			"%s%s%s Test case #%d\n" ANSI_DIM "  Expected : %s\n"
			"  Got      : %s\n" ANSI_RESET,
			ok ? ANSI_BOLD ANSI_GREEN : ANSI_BOLD ANSI_RED,
			ok ? "[  OK  ]" : "[ FAIL ]",
			ANSI_RESET,
			case_no,
			line_exp ? buf_exp : "(EOF)",
			line_out ? buf_out : "(EOF)" );

		printf( "\n" );

		if ( ok ) {
			passed++;
		}

		case_no++;
	}

	printf( "Resumo: %d/%d test cases passaram.\n\n", passed, total );

	fclose( f_exp );
	fclose( f_out );
	return ( passed == total ) ? 0 : 1;
}
