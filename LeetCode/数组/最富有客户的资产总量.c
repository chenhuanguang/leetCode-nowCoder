int funmax(int a, int b)
{
	return a > b ? a : b;
}

int maximumWealth(int* accounts[], int accountsSize, int* accountsColSize) 
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < accountsSize; i++)
	{
		for (int j = 0; j < *accountsColSize; j++)
		{
			sum += accounts[i][j];
		}
		max = funmax(max, sum);
		sum = 0;
	}
	return max;
}