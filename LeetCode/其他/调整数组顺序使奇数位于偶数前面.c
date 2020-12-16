int* exchange(int* nums, int numsSize, int* returnSize){

	*returnSize = numsSize;

	int l = 0;
	int r = numsSize - 1;

	while (l < r)
	{
		if ((nums[l] & 1) != 0)
		{
			l++;
			continue;
		}
		if ((nums[r] & 1) != 1)
		{
			r--;
			continue;
		}
		int temp = nums[l];
		nums[l++] = nums[r];
		nums[r--] = temp;
	}
	
	return nums;

}