/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
       
         if(l1==NULL || l2==NULL)
            return l1==NULL ? l2:l1;
        struct ListNode* newHead, *cur1, *cur2, *tail;
        cur1 = l1;
        cur2 = l2;
        if(l1->val<=l2->val)
        {
            newHead = l1;
            cur1 = cur1->next;
        }
        else
        {
            newHead = l2;
            cur2 = cur2->next;
        }
        tail = newHead;
        while(cur1 && cur2)
        {
            if(cur1->val<=cur2->val)
            {
                tail->next = cur1;
                cur1 = cur1->next;
                tail = tail->next;
            }
            else
            {
                 tail->next = cur2;
                 cur2 = cur2->next;
                 tail = tail->next;
            }
        }  
        if(cur1)
            tail->next = cur1;
        if(cur2)
            tail->next = cur2;
        return newHead;  
    }
};