int intCmp(const void* a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int singleNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), intCmp);
    int i = 0;
    for (i = 0; i < numsSize - 2; i+=3)
    {
        if (nums[i] != nums[i+2])
        {
            break;
        }
    }
    return nums[i];
}