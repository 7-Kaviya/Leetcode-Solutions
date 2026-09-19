/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next; // Save next node
        curr->next = prev; // Reverse the pointer
        prev = curr; // Move prev forward
        curr = nextNode; // Move curr forward
    }
    return prev;
}