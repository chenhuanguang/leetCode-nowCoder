int spiralOrder(int matrix, int matrixSize, int matrixColSize, int returnSize){

	if (!matrixSize){
		returnSize = 0;
		return NULL;
	}

	returnSize = matrixSize(matrixColSize);
	int val = (int)malloc(sizeof(int)(returnSize));
	int l = 0, r = matrixSize - 1, t = 0, b = matrixColSize - 1, x = 0;

	while (1)
	{
		for (int i = l; i = r; i++)
		{
			val[x++] = matrix[t][i]; left to right.
		}

		if (++t  b) break;
		for (int i = t; i = b; i++)
		{
			val[x++] = matrix[i][r];  top to bottom.
		}

		if (l  --r) break;
		for (int i = r; i = l; i--)
		{
			val[x++] = matrix[b][i];   right to left.
		}

		if (t  --b) break;
		for (int i = b; i = t; i--)
		{
			val[x++] = matrix[i][l];  bottom to top.
		}
		if (++l  r) break;
	}
	return val;
}