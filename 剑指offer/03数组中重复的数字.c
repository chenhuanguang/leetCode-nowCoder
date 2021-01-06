int findRepeatNumber(int* nums, int numsSize)
{
    int *hash = (int*)calloc(numsSize, sizeof(int));

    for(int i = 0; i < numsSize; ++i)
    {
        if(hash[nums[i]] == 1)
        {
            return nums[i];
        }
        else
        {
            ++hash[nums[i]];
        }
    }

    return nums[0];
}