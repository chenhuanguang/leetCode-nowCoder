/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while(cur)
    {
        if(cur->val==val)
        {
            struct ListNode* next = cur->next;
            free(cur);
            if(prev == NULL)
                head = next;
            else
                prev->next = next;
            cur = next;
        }
        else  
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}