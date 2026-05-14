#ifndef LEETCODE_H
#define LEETCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
============================================================
PUBLIC Interface — lc_array.c
============================================================ 
*/

/* Parses "[1,2,3]" → allocated array of ints. *len receives the length */
int *lc_parse_array( const char *s, int *len );

/* Parses "[[1,2],[3,4]]" → allocated matrix. *rows and *cols populated. */
// int **lc_parse_matrix( const char *s, int *rows, int *cols );

void lc_free_matrix( int **m, int rows );

/* Prints array and matrix formatted. */
void lc_print_array( const int *arr, int len );
void lc_print_matrix( int **m, int rows, int cols );

#endif /* LEETCODE_H */
