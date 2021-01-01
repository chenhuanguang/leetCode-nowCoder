
int CompareInt(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

bool isStraight(int* nums, int numsSize)
{
    if(nums == NULL)
    {
        return false;
    }

    int total = 0;

    qsort(nums, numsSize, sizeof(int),CompareInt);

    for(int i = 0; i < numsSize -1; ++i)
    {
        if(nums[i] == 0)
        {
            ++total;
            continue;
        }

        if(nums[i] == nums[i+1])
        {
            return false;
        }
    }
    int min = nums[total];
    int max = nums[numsSize-1];

    return max- min < 5;
}
