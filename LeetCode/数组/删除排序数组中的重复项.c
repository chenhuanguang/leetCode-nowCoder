int removeDuplicates(int* nums, int numsSize){

    if(numsSize<=1)
        return numsSize;
    int i=0,j=1,idx = 0;
    while(j<numsSize)
    {
        nums[idx++]=nums[i];

        if(nums[i]==nums[j])
        {
            while(j<numsSize && nums[i]==nums[j])
            {
                ++j;
            }     
            i=j;
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    if(i<numsSize)
    {
        nums[idx++]=nums[i];
    }
    return idx;
}