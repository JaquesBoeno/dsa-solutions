#include "leetcode.h"

#include <stdio.h>

struct ListNode {
	int				 val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbers( struct ListNode *l1, struct ListNode *l2 );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) != NULL ) {

		int i		 = strcspn( lineBuff, "\n" );
		lineBuff[i]	 = '\0';
		ListNode *l1 = lc_parse_list( lineBuff );

		if ( fgets( lineBuff, sizeof( lineBuff ), stdin ) == NULL ) {
			break;
		}

		i			 = strcspn( lineBuff, "\n" );
		lineBuff[i]	 = '\0';
		ListNode *l2 = lc_parse_list( lineBuff );

		ListNode *r = addTwoNumbers( l1, l2 );

		lc_list_print( r );
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
struct ListNode *addTwoNumbers( struct ListNode *l1, struct ListNode *l2 ) {
	struct ListNode *head  = ( struct ListNode * )malloc( sizeof( struct ListNode ) );
	head->next			   = NULL;
	int				 carry = 0;
	struct ListNode *c	   = head;

	while ( l1 || l2 || carry ) {
		int k = carry;
		if ( l1 != NULL ) {
			k += ( l1->val );
			l1 = l1->next;
		}
		if ( l2 != NULL ) {
			k += l2->val;
			l2 = l2->next;
		}

		c->val = k % 10;
		carry  = ( k / 10 );

		if ( l1 || l2 || carry ) {
			c->next			  = ( struct ListNode * )malloc( sizeof( struct ListNode ) );
			( c->next )->next = NULL;
			c				  = c->next;
		}
	}
	return head;
}
