typedef struct 
{
    int pushTop; //栈顶
    int popTop;
    int *pushStack;
    int *popStack;
    int len;  //栈大小长度
} CQueue;


CQueue* cQueueCreate() {
    CQueue* cq = (CQueue*)malloc(sizeof(CQueue));
    cq->len = 1000;
    cq->pushStack = (int*)malloc(sizeof(int) * cq->len);
    cq->popStack = (int*)malloc(sizeof(int) * cq->len);
    cq->pushTop = -1;
    cq->popTop = -1;

    return cq;
}

void cQueueAppendTail(CQueue* obj, int value) 
{
    obj->pushStack[++(obj->pushTop)] = value;
}

int cQueueDeleteHead(CQueue* obj) 
{
    //出队的栈没元素
    if (obj->popTop == -1)
    {
        //入队的栈也没元素
        if (obj->pushTop == -1)
        {
            return -1;
        }
        else
        {
            //将入队的栈的所有元素导入出队的栈
            while(obj->pushTop > -1)
            {
                obj->popStack[++(obj->popTop)] = obj->pushStack[(obj->pushTop)--];
            }
        }
    }

    return obj->popStack[(obj->popTop)--];
}

void cQueueFree(CQueue* obj) 
{
    free(obj->pushStack);
    obj->pushStack = NULL;
    free(obj->popStack);
    obj->popStack = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/