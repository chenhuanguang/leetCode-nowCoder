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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next ==NULL)
            return head;
        struct ListNode* node = head->next;
        struct ListNode* cur = head;
        struct ListNode* tail = head;

        while(node)
        {
            struct ListNode* next = node->next;
            if(node->val > tail->val)
            {
                tail->next = node;
                tail = node;
            }
            else
            {
                struct ListNode* prev = NULL;
                while(node->val > cur->val)
                {
                    prev = cur;
                    cur = cur->next;
                }
                if(prev == NULL)
                {
                    node->next = head;
                    head = node; 
                }
                else
                {
                    prev->next = node;
                    node->next = cur;
                }
                node = next;
                cur = head;
            }
        }
        tail->next = NULL;
        return head;
    }
};