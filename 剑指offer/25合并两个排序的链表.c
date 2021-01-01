/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL || l2 == NULL)
    {
        return l1 == NULL ? l2 : l1;
    }
        
    struct ListNode *cur1 = l1;
    struct ListNode *cur2 = l2;
    struct ListNode *newHead;
    struct ListNode *tail;

    if(l1->val < l2->val)
    {
        newHead = cur1;
        cur1 = cur1->next;
    }
    else
    {
        newHead = cur2;
        cur2 = cur2->next;
    }
    tail = newHead;

    while(cur1 && cur2)
    {
        if(cur1->val < cur2->val)
        {
            tail->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            tail->next = cur2;
            cur2 = cur2->next;
        }
        tail = tail->next;
    }
    
    if(cur1)
    {
        tail->next = cur1;
    }  
    if(cur2)
    {
        tail->next = cur2;
    }
       
    return newHead;
}