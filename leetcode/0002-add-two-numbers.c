/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head  = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next			   = NULL;
	int				 carry = 0;
	struct ListNode* c	   = head;

	while (l1 || l2 || carry) {
		int k = carry;
		if (l1 != NULL) {
			k += (l1->val);
			l1 = l1->next;
		}
		if (l2 != NULL) {
			k += l2->val;
			l2 = l2->next;
		}

		c->val = k % 10;
		carry  = (k / 10);

		if (l1 || l2 || carry) {
			c->next			= (struct ListNode*)malloc(sizeof(struct ListNode));
			(c->next)->next = NULL;
			c				= c->next;
		}
	}
	return head;
}
