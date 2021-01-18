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
 int getSize(struct TreeNode* root)
{
    if (root)
    {
        return getSize(root->left) + getSize(root->right) + 1;
    }
    return 0;
}

typedef struct TreeNode* STDataType;
typedef struct Stack {
	STDataType* _a;
	int _top;// 栈顶
	int _capacity; // 容量
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

//检查容量
void CheckCapacity(Stack* ps)
{
	if (ps->_top == ps->_capacity)
	{
		size_t newCapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newCapacity * sizeof(STDataType));
		if (!ps->_a)
			return;
			ps->_capacity = newCapacity;
	}
}

// 入栈
void StackPush(Stack* ps, STDataType data)
{
	CheckCapacity(ps);
	ps->_a[ps->_top++] = data;

}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = getSize(root);
    int* arr = malloc(sizeof(int) * size);
    Stack st;
    StackInit(&st);
    int idx = 0;
    //上一次访问的结点
    struct TreeNode* prev = NULL;

    while(root || !StackEmpty(&st))
    {
        //1、遍历最左路径
       while(root)
        { 
            StackPush(&st, root);
            root = root->left;
        }

        //栈顶的结点
        struct TreeNode* top = StackTop(&st);
        //判断栈顶元素是否可以访问
        //可以访问的情况：没有右子树 || 右子树访问完成
        //右子树访问完成：上一次访问的结点为右子树的根节点
        if (top->right == NULL || top->right == prev)
        {
            //可以访问当前栈顶元素
            arr[idx++] = top->val;
            StackPop(&st);
            prev = top;
        }
        else
        {
            //右子树没访问
            root= top->right;
        }
    }

    *returnSize = idx;
    return arr;
}