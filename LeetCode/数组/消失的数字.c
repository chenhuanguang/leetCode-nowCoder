int missingNumber(int* nums, int numsSize) 
{
	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i <= numsSize; i++)
	{
		sum += i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		sum1 += nums[i];
	}
	return sum-sum1;
}