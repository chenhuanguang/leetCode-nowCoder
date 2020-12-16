int max(int a, int b)
{
	return (a > b) ? a : b;
}

int massage(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int *dp = (int*)malloc(sizeof(int)*numsSize);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	int i;
	for ( i= 2; i < numsSize; i++)
	{
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[i - 1];
}