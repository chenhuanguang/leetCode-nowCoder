bool isStraight(int* nums, int numsSize){


	for (int i = 0; i < numsSize-1; ++i)
	{
		for (int j = 0; j < numsSize - 1 - i; ++j)
		{

            if (nums[j]==nums[j + 1]&&nums[j]!=0)
            {
                return false;
            }
                   

			if (nums[j]>nums[j + 1])
			{
				int tmp = nums[j+1];
				nums[j + 1] = nums[j];
				nums[j] = tmp;
			}
		}
	}

	int joker = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
		{
			joker++;
		}
	}
	return (nums[4] - nums[joker]<5);

}