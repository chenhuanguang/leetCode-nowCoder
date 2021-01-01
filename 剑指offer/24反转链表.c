/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *cur = head;
    struct ListNode *newHead = NULL;

    while(cur != NULL)
    {
        struct ListNode *next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    
    return newHead;
}