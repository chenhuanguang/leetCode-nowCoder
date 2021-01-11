/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    if (numsSize == 0 || k == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int* arr = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int idx = 0;

    for (int i = 0; i <= numsSize - k; ++i)
    {
        int max = nums[i];
        for (int j = i + 1; j < i + k; ++j)
        {
            if (nums[j] > max)
            {
                max = nums[j];
            }
        }
        arr[idx++] = max;
    }
    *returnSize = idx;
    return arr;
}