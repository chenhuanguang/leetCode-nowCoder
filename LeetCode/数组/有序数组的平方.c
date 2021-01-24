/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int i;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] > 0)
            break;
    }

    int negativeEnd = i - 1;
    int positiveBegin = i;

    int* arr = (int*)malloc(sizeof(int) * numsSize);
    int idx = 0;
    while (negativeEnd >= 0 || positiveBegin < numsSize)
    {
        if (negativeEnd < 0)
        {
            arr[idx++] = nums[positiveBegin] * nums[positiveBegin];
            positiveBegin++;
        }
        else if (positiveBegin >= numsSize)
        {
            arr[idx++] = nums[negativeEnd] * nums[negativeEnd];
            negativeEnd--;
        }
        else if ((nums[negativeEnd] * nums[negativeEnd]) < (nums[positiveBegin] * nums[positiveBegin]))
        {
            arr[idx++] = nums[negativeEnd] * nums[negativeEnd];
            negativeEnd--;
        }
        else
        {
            arr[idx++] = nums[positiveBegin] * nums[positiveBegin];
            positiveBegin++;
        }
    }

    *returnSize = idx;
    return arr;
}