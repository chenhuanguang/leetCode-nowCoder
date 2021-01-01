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
    Node* copyRandomList(Node* head) 
    {
        if(head == NULL)
            return NULL;
        struct Node *cur = head;
      
        while(cur)
        {
            struct Node *next = cur->next;
            struct Node *newNode = (Node*)malloc(sizeof(struct Node));
            newNode->val = cur->val;
            cur->next = newNode;
            newNode->next = next;
            cur = next;
        } 

        cur = head;
        while(cur)
        {
            struct Node *node = cur->next;
            if(cur->random)
            {
                node->random = cur->random->next;
                
            }
            else
            {
               node->random = NULL;
            }
            cur = node->next;
        }

        cur = head;
        struct Node* newNode = NULL;
       
        while(cur)
        {
            struct Node *copy = cur->next;
            struct Node *next = copy->next;
            cur->next = next;
            if(newNode == NULL)
            {
                newNode = copy;
            }
            if(next)
            {
                copy->next = next->next;
            }
            cur = next;
        }
        return newNode;
    }
};