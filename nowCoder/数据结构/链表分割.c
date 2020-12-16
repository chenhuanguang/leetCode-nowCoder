class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
       if(pHead == NULL)
           return pHead;
       struct ListNode* s = (struct ListNode*)malloc(sizeof(ListNode));
       struct ListNode* b = (struct ListNode*)malloc(sizeof(ListNode));
       struct ListNode* cur = pHead;
       struct ListNode* stail = s;
       struct ListNode* btail = b;
        
       while(cur)
       {
           struct ListNode* next = cur->next;
           if(cur->val<x)
           {
               stail->next = cur;
               stail = stail->next;
                
           }
           else
           {
               btail->next = cur;
               btail = btail->next;
           }
           cur = next;
       }
         
        if(btail)
            btail->next = NULL;
        stail->next = b->next;
        struct ListNode* newHead = s->next;
        free(b);
        free(s);
        return newHead;
    }
};