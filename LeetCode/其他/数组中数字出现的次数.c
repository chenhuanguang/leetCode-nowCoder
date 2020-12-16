int* singleNumbers(int* nums, int numsSize, int* returnSize) 
{
	*returnSize = 2;
	int x = 0;
	int y = 0;
	int ret = 0;
	int pos = 0;
	int *pnum = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	for (int i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
			pos = i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (((nums[i] >> pos) & 1) == 1)
			x ^= nums[i];
		else
			y ^= nums[i];
	}
	pnum[0] = x;
	pnum[1] = y;
    
	return pnum;
}