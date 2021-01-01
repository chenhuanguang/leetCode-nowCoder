/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    if(nums == NULL || numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int x = 0;
    int y = 0;
    int ret = nums[0];
    int pos = 0;
    *returnSize = 2;
    int *arr = (int*)malloc(sizeof(int) * 2);

    //获得这两个数的异或的结果
    for(int i = 1; i < numsSize; ++i)
    {
        ret^=nums[i];
    }

    //最高位的1来区分两个数，获得索引
    for(int i = 0; i < 32; ++i)
    {
        if(((ret >> i) & 1) == 1)
        {
            pos = i;
        }
    }

    //通过上一步获得的索引，将两个数分开
    for(int i = 0; i < numsSize; ++i)
    {
        if(((nums[i] >> pos) & 1) == 1)
        {
            x^=nums[i];
        }
        else
        {
            y^=nums[i];
        }
    }

    arr[0] = x;
    arr[1] = y;
    return arr;

}