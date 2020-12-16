/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A)
    {
        if(A == NULL)
            return false;
        struct ListNode* slow,*fast,*newHead,*cur,*next,*strat,*strat2;
        slow = fast = A;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        newHead = NULL;
        cur = slow;
        while(cur)
        {
            next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        strat = A;
        strat2 = newHead;
        while(strat && strat2)
        {
            if(strat->val == strat2->val)
            {
                strat = strat->next;
                strat2 = strat2->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};