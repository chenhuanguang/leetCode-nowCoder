int* printNumbers(int n, int* returnSize)
{
    int MaxNum = 1;
    while(n--)
    {
        MaxNum*= 10;
    }
    int* arr = (int*)malloc(sizeof(int) * (MaxNum-1));
    int idx = 0;
    for(int i = 1; i < MaxNum; ++i)
    {
        arr[idx++] = i;
    }
    *returnSize = MaxNum - 1;
    return arr;
}
