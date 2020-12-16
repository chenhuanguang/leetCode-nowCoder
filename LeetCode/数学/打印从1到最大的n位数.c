int* printNumbers(int n, int* returnSize) {

	int count = pow(10, n) - 1;
	int *nums= (int*)malloc(sizeof(int)*count);
	*returnSize = count;
	for (int i = 0; i <count; i++)
	{
		nums[i] = i + 1;
	}
	return nums;
}