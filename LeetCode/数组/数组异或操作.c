int xorOperation(int n, int start) {

	int result = start;
	for (int i = 0; i < n-1; i++)
	{
		result ^= start + 2 * (i + 1);
	}
	return result;
}