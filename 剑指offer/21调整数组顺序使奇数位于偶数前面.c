int* exchange(int* nums, int numsSize, int* returnSize)
{
    if(nums == NULL)
    {
        return NULL;
    }
    int head = 0;
    int tail = numsSize-1;

    while(head < tail)
    {
        if(nums[head] % 2 == 0 && nums[tail] % 2 == 1)
        {
            nums[head] = nums[head] ^ nums[tail];
            nums[tail] = nums[head] ^ nums[tail];
            nums[head] = nums[head] ^ nums[tail];
        }
        if(nums[head] % 2 == 1)
        {
            ++head;
        }
        if(nums[tail] % 2 == 0)
        {
            --tail;
        }
    }
    *returnSize = numsSize;

    return nums;
}
