/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL||headB == NULL)
            return NULL;
        ListNode* A = headA;
        ListNode* B = headB;
       while(A!=B)
       {
           if(A)
           {
               A = A->next;
           }
           else
           {
               A = headB;
           }
           if(B)
           {
               B = B->next;
           }
           else{
               B = headA;
           }
       }
       return A;
    }
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode* curA, *curB;
    curA = headA;
    curB = headB;
    int lenA = 0;
    int lenB = 0;
    while(curA)
    {
        ++lenA;
        curA = curA->next;
    }
    while(curB)
    {
        ++lenB;
        curB = curB->next;
    }
    curA = headA;
    curB = headB;
    int gap = abs(lenA-lenB);
    if(lenA>lenB)
    {
        while(gap--)
        {
            curA = curA->next;
        }
    }
    else
    {
        while(gap--)
        {
            curB = curB->next;
        }
    }
    while(curA && curB)
    {
        if(curA == curB)
            return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}