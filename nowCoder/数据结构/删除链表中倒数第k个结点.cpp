/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    int getSize(ListNode* head)
    {
        int size = 0;
        while (head)
        {
            ++size;
            head = head->next;
        }
        return size;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // write code here
        ListNode* tmp = new ListNode(0);
        tmp ->next = head;
        ListNode* cur = tmp;
        int size = getSize(head);
        for (int i = 1; i < size - n + 1; ++i)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* res = tmp->next;
        delete tmp;
        return res;
    }
};