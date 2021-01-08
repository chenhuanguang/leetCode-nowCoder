/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int count1 = 0;
    int count2 = 0;
    int res1 = 0;
    int res2 = 0;
    int* arr = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; ++i)
    {
        if (res1 == nums[i])
        {
            ++count1;
            continue;
        }

        if (res2 == nums[i])
        {
            ++count2;
            continue;
        }

        if (count1 == 0)
        {
            res1 = nums[i];
            ++count1;
            continue;
        }

        if (count2 == 0)
        {
            res2 = nums[i];
            ++count2;
            continue;
        }

        --count1;
        --count2;
    }

    count1 = count2 = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] == res1)
            ++count1;
        else if (nums[i] == res2)
            ++count2;
    }

    if (count1 > (numsSize / 3) && count2 > (numsSize / 3))
    {
        arr[0] = res1;
        arr[1] = res2;
        *returnSize = 2;
        return arr;
    }
    else if (count1 > (numsSize / 3))
    {
        arr[0] = res1;
        *returnSize = 1;
        return arr;
    }
    else if (count2 > (numsSize / 3))
    {
        arr[0] = res2;
        *returnSize = 1;
        return arr;
    }
    
    *returnSize = 0;
    return arr;

}