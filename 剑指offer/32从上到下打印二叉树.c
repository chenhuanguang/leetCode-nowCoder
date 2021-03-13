/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode* QDataType;

typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* _front;
	struct QueueNode* _back;
	int _size;
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
	q->_size = 0;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->_data = data;
	newNode->_next = NULL;

	if (q->_back == NULL)
	{
		q->_front = q->_back = newNode;
	}
	else
	{
		q->_back->_next = newNode;
		q->_back = newNode;
	}
	q->_size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	if (q == NULL || q->_front == NULL)
		return;
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QueueNode* second = q->_front->_next;
		free(q->_front);
		q->_front = second;
	}
	q->_size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_back = q->_front = NULL;
}

int* levelOrder(struct TreeNode* root, int* returnSize)
{
    Queue q;
    QueueInit(&q);
    int* res = (int*)malloc(sizeof(int) * 1009);
    if (root)
    {
        QueuePush(&q, root);
    }
    int idx = 0;
    while (!QueueEmpty(&q))
    {
        struct TreeNode *node = QueueFront(&q);
        QueuePop(&q);
        res[idx++] = node->val;
        if (node ->left != NULL)
        {
            QueuePush(&q, node->left);
        }
        if (node ->right != NULL)
        {
            QueuePush(&q, node->right);
        }
    }
    QueueDestroy(&q);
    *returnSize = idx;
    return res;
}