int minCount(int* coins, int coinsSize) 
{
	int result = 0;
	int single = 0;
	for (int i = 0; i < coinsSize; i++)
	{
		if (coins[i] > 0&& coins[i]%2==0)
		{
			single = coins[i] / 2;
		}
		else if(coins[i] > 0 && coins[i] % 2 != 0)
		{
			single = coins[i] / 2+1;
		}
		result += single;
	}
	
	return result;

}