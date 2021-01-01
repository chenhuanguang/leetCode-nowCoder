/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if(head == NULL)
        return NULL;
    struct ListNode *slow, *fast;
    slow = fast = head;
    while(fast && k--)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}