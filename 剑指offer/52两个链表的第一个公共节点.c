/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }

    struct ListNode *cur1 = headA;
    struct ListNode *cur2 = headB;

    while(1)
    {
        if(cur1 == cur2)
        {
            return cur1;
        }
        else
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        if(cur1 == NULL && cur2 == NULL)
            break;
        if(cur1 == NULL)
            cur1 = headB;
        if(cur2 == NULL)
            cur2 = headA;
    }
    return NULL;
}