typedef struct {
    int* array;
    int n;      // 数组的空间大小
    int front;  //队头
    int rear;   //队尾
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->array = malloc(sizeof(int)*(k+1));
    cq->n = k+1;
    cq->front = 0;
    cq->rear = 0;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    obj->array[obj->rear] = value;
    obj->rear++;
    if(obj->rear == obj->n)
        obj->rear = 0;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    
    obj->front++;
    if(obj->front == obj->n)
        obj->front = 0;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    return obj->array[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    int prevRear = obj->rear-1;
    if(obj->rear == 0)
        prevRear = obj->n-1;

     return obj->array[prevRear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    int rearNext = obj->rear+1;
    rearNext %= obj->n;
    return rearNext == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);


}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/