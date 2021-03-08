/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divingBoard(int shorter, int longer, int k, int* returnSize)
{
    if (k == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    if (shorter == longer)
    {
        int *arr = (int*)malloc(sizeof(int));
        arr[0] = k * longer;
        *returnSize = 1;
        return arr;
    }
    int *arr = (int*)malloc(sizeof(int) * (k +1));
    int tmp = k;
    int idx = 0;
    
    while (tmp >= 0)
    {
        arr[idx++] = tmp * shorter + (k - tmp) * longer;
        --tmp;
    } 
    *returnSize = idx;
    return arr;
}