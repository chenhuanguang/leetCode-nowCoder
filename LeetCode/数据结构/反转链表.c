struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* newHead,*cur;
    cur = head;
    newHead = NULL;

    while(cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;
}