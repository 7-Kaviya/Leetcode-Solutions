/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *c = head, *p = NULL, *h = head;
    for (; c ; c = c->next)
        if (c->val == val)
            p ? (p->next = c->next) : (h = h->next);
        else
            p && (p->next = c), p = c;
    return h;
}