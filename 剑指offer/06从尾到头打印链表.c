/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize)
{
    struct ListNode *newHead, *cur;
    newHead = NULL;
    cur = head;
    int size = 0;

    while(cur != NULL)
    {
        struct ListNode *next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
        ++size;
    }

    int *arr = (int*)malloc(sizeof(int) * size);
    cur = newHead;
    int idx = 0;

    while(cur != NULL)
    {
        arr[idx++] = cur->val;
        cur = cur->next;
    }
    *returnSize = size;

    return arr;
}