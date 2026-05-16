#include "leetcode.h"

#include <stdio.h>
#include <string.h>

struct ListNode *mergeTwoLists( struct ListNode *list1, struct ListNode *list2 );

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

		ListNode *r = mergeTwoLists( l1, l2 );

		lc_list_print( r );
	}

	return 0;
}

struct ListNode *mergeTwoLists( struct ListNode *list1, struct ListNode *list2 ) {
	struct ListNode dumby;

	dumby.val = -1000;

	struct ListNode *curr = &dumby;

	for ( ; curr; curr = curr->next ) {
		if ( list1 == NULL ) {
			curr->next = list2;
			break;
		} else if ( list2 == NULL ) {
			curr->next = list1;
			break;
		}

		if ( list1->val < list2->val ) {
			curr->next = list1;
			list1	   = list1->next;
		} else {
			curr->next = list2;
			list2	   = list2->next;
		}
	}
	return dumby.next;
}
