/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        struct ListNode* fast = pListHead;
        struct ListNode* slow = pListHead;
        while(k--)
        {
            if(fast)
                fast = fast->next;
            else
                return NULL;
        }
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
}