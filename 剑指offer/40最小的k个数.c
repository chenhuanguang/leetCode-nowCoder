int CompareInt (const void* a,const void* b)
{
    return (*(int*)a - *(int*)b);
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
    qsort(arr, arrSize,sizeof(int),CompareInt);
    *returnSize = k;
    int* arr2 = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < k; ++i)
    {
        arr2[i] = arr[i];
    }
    return arr2;
}