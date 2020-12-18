/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        struct Node* cur = head;
        //拷贝结点到 该结点的下一个位置
        while(cur)
        {
            struct Node* next = cur->next;
            struct Node* node = (struct Node*)malloc(sizeof(Node));
            node->val = cur->val;
            cur->next = node;
            node->next = next;
            cur = next;
        }

        //拷贝随机指针
        cur = head;
        while(cur)
        {
            struct Node* node = cur->next;
            if(cur->random)
                node->random = cur->random->next;
            else
                node->random = NULL;
            cur = node->next;
            
        }

        //断链
        cur = head;
        struct Node* newHead = NULL;
        while(cur)
        {
            struct Node* copy = cur->next;
            struct Node* next = copy->next;
            
            cur->next = next;
            if(newHead == NULL)
                newHead = copy;
            if(next)
                copy->next = next->next;
            cur = next;
        }
        return newHead;
    }
};