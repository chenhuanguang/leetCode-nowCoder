//简单粗暴
int search(int* nums, int numsSize, int target)
{
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (target < nums[i])
        {
            break;
        }

        if (nums[i] == target)
        {
            ++count;
        }
    }

    return count;
}

//查找到元素，再查左右边界
int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int count = 0;

    while(left <= right)
    {
        int mid = (left + right) >> 1;

        if (nums[mid] == target)
        {
            for(int i = mid - 1; i >= 0 && nums[i] == target; --i)
            {
                ++count;
            }
            for(int i = mid; i < numsSize && nums[i] == target; ++i)
            {
                ++count;
            }

            break;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        
    }

    return count;
}

//查找当前值的右边界和当前值 - 1的右边界 两者相减
int BinarySearch(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while(left <= right)
    {
        int mid = (left + right) >> 1;
        //获得值为target的最后一个元素的索引
        if (nums[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left; 
}

int search(int* nums, int numsSize, int target)
{
    return BinarySearch(nums, numsSize, target) - BinarySearch(nums, numsSize, target - 1);
}