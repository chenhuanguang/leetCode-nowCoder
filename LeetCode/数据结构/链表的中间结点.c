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
    ListNode* middleNode(ListNode* head) 
    {
         struct ListNode* slow = head;
         struct ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow ->next;
        }
        return slow;
    }
};