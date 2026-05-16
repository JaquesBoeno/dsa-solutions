#include "leetcode.h"

#include <stdio.h>
#include <string.h>

struct ListNode *middleNode( struct ListNode *head );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';

		ListNode *Li = lc_parse_list( lineBuff );
		ListNode *Lr = middleNode( Li );

		lc_list_print( Lr );
	}

	return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *middleNode( struct ListNode *head ) {
	int				 i = 0;
	struct ListNode *a = head, *b = head;

	while ( b != NULL ) {
		if ( i % 2 == 1 ) {
			b = b->next;
			a = a->next;
		} else {
			b = b->next;
		}
		i++;
	}

	return a;
}
