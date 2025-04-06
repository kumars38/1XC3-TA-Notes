#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

// Testing
void print(struct ListNode *head) {
    while (head != NULL) {
        printf("%d -> ",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode* reverseList(struct ListNode *head) {
	struct ListNode* store;
    struct ListNode* prev = NULL;
    struct ListNode* ntt = head;

	while (ntt != NULL) {
        store = ntt->next;
        ntt->next=prev;
        prev=ntt;
        ntt=store;
    }
    return prev;
}

struct ListNode* reverseList3(struct ListNode *head) {
	struct ListNode* prev = NULL;
    // Reverse each node while we traverse
    // (set next to point to prev) 
	while (head != NULL) {
        // save pointer to original next node
		struct ListNode* next = head->next;
        // reverse the nodes
		head->next = prev;
        // update previous for next node
		prev = head;
        // traverse to original next node
		head = next;
	}
    // because our loop condition is while head != NULL:
    // if we return head, we will return NULL
    // prev is the one we want (actual last node)
    return prev;
}

int main() {
    // Testing
    struct ListNode a, b, c, d;
    a.val = 1; a.next = &b;
    b.val = 2; b.next = &c;
    c.val = 3; c.next = &d;
    d.val = 4; d.next = NULL;
    print(&a);

    struct ListNode *rev = reverseList(&a);
    print(rev);
}