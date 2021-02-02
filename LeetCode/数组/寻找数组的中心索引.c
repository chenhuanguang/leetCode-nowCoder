int pivotIndex(int* nums, int numsSize)
{   
    int total = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        total += nums[i];
    }

    for (int i = 0; i < numsSize; ++i)
    {
        if ((2 * sum) + nums[i] == total)
            return i;
        sum += nums[i];
    }

    return -1;
}