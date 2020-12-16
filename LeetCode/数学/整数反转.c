int reverse(int x)
{
	long sum = 0;
	while (x != 0)
	{
		sum = sum * 10 + x % 10;
		x=x / 10;
	}
	if ((int)sum != sum)
		return 0;
	return (int)sum;
}