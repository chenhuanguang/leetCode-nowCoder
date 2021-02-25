int compareInt(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findUnsortedSubarray(int* nums, int numsSize)
{
    int* copy = (int*)malloc(sizeof(int) * numsSize);
    memcpy(copy, nums, sizeof(int) * numsSize);
    qsort(copy, numsSize, sizeof(int), compareInt);
    int head = 0, tail = head;
    //从前往后找不同
    for(int i = 0; i < numsSize; ++i)
    {
        if (copy[i] != nums[i])
        {
            head = i;
            break;
        }
    }
    //从后往前找不同
    for (int i = numsSize - 1; i >= 0; --i)
    {
        if (copy[i] != nums[i])
        {
            tail = i;
            break;
        }
    }

    if (head == tail)
    {
        return 0;
    }
    return tail - head + 1;
}