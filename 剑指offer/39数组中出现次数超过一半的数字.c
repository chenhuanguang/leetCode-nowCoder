// int CompareInt(const void* a, const void*b)
// {
//     return *(int*)a - *(int*)b;
// }

// //排序 nlogn + O(1)
// int majorityElement(int* nums, int numsSize)
// {
//     qsort(nums, numsSize, sizeof(nums[0]),CompareInt);
//     return nums[numsSize / 2];
// }

//摩尔投票
int majorityElement(int* nums, int numsSize)
{
    int count = 0;
    int res = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (count == 0)
        {
            ++count;
            res = nums[i];
        }
        else if (nums[i] == res)
        {
            ++count;
        }
        else
        {
            --count;
        }
    }

    return res;
}
