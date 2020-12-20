/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL ||pHead->next ==NULL)
            return pHead;
        struct ListNode* prev = NULL;
        struct ListNode* cur = pHead;
        struct ListNode* next = cur->next;
        while(next)
        {
            if(cur->val == next->val)
            {
                while(next && next->val == cur->val)
                {
                    next = next->next;
                }
                while(cur!=next)
                {
                    struct ListNode* next = cur->next;
                    free(cur);
                    cur = next;
                }
                if(prev == NULL)
                {
                    pHead = cur;
                }
                else
                {
                    prev->next = cur;
                }
                if(next)
                {
                    next = next->next;
                }
            }
            else
            {
                prev = cur;
                cur = next;
                next = next->next;
            }
        }
        return pHead;
    }
};