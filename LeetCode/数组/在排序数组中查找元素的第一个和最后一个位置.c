/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int binarySearch(int* nums, int numsSize, int target, bool flag)
{
    int left = 0;
    int right = numsSize - 1;
    int idx = numsSize;
    while (right >= left)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (flag && nums[mid] >= target))
        {
            right = mid - 1;
            idx = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return idx;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * 2);
    int left = binarySearch(nums, numsSize, target, true);
    int right = binarySearch(nums, numsSize, target, false) - 1;
    *returnSize = 2;
    if (left <= right && right < numsSize && nums[left] == target && nums[right] == target)
    {
        res[0] = left;
        res[1] = right;
        return res;
    }
    res[0] = -1;
    res[1] = -1;

    return res;
}

