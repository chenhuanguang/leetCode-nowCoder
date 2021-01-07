int thirdMax(int* nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1]; 
        
    int max1,max2,max3;
    max1 = max2 = max3 = INT_MIN;
    int tmp1, tmp2, tmp3;
    tmp1 = tmp2 = tmp3 = nums[0];

    for (int i = 0; i < numsSize; ++i)
    {
        if(nums[i] != tmp1)
        {
            if(tmp1 != tmp2)
            {
                tmp3 = nums[i];
            }
            else
            {
                tmp2 = nums[i];
            }
        }

        if (nums[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] < max1 && nums[i] > max2)
        {
            max3 = max2;
            max2 = nums[i];
        }
        else if (nums[i] < max2 && nums[i] > max3)
        {
            max3 = nums[i];
        }
    }
    
    if (tmp1 == tmp3 || tmp2 == tmp3)
    {
        return max1;
    }
    else
    {
        return max3;
    }
}

// int thirdMax(int* nums, int numsSize)
// {
//     if (numsSize == 1)
//         return nums[0];
//     if (numsSize == 2)
//         return nums[0] > nums[1] ? nums[0] : nums[1];
//     long max1 = -2147483649;
//     long max2 = -2147483649;
//     long max3 = -2147483649;

//     for(int i = 0; i < numsSize; ++i)
//     {
//         if (nums[i] > max1)
//         {
//             max1 = nums[i];
//         }
//     }

//     for(int i = 0; i < numsSize; ++i)
//     {
//         if (nums[i] == max1)
//             continue;
//         if (nums[i] > max2)
//         {
//             max2 = nums[i];
//         }
//     }

//     int flag = 0;
//     for(int i = 0; i < numsSize; ++i)
//     {
//         if (nums[i] == max1 || nums[i] == max2)
//             continue;
//         if (nums[i] > max3)
//         {
//             max3 = nums[i];
//             flag = 1;
//         }
//     }

//     if (flag)
//         return max3;
//     else
//         return max1;
// }