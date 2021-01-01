/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val)
{
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode *cur, *prev;
    cur = head;
    prev = NULL;
    while(cur != NULL)
    {
        struct ListNode* next = cur->next;
        if(cur->val == val)
        {
           if(prev == NULL)
           {
               head = next;
           }
           else
           {
               prev->next = next;
               free(cur);
           }
        }
        else
        {
            prev = cur;
        }
        cur = next;
    }
    return head;
}