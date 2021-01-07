/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i = 0;
    int j = numsSize - 1;
    int* arr = (int*)malloc(sizeof(int) * 2);
    while(i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum > target)
        {
            --j;
        }
        else if (sum < target)
        {
            ++i;
        }
        else
        {
            break;
        }
    }
    
    arr[0] = nums[i];
    arr[1] = nums[j];
    *returnSize = 2;
    
    return arr;
}