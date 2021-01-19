int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int res = numsSize;
    while (left <= right)
    {
        int mid = (left +right) / 2;

        if (target > nums[mid])
        {
            left = mid + 1;
        }
        else 
        {
            res = mid;
            right = mid - 1;
        }    
    }
    return res;
}