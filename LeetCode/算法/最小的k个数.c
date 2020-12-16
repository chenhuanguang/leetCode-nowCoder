int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){

	int *arr2=arr;
    *returnSize = k;
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		arr2[i] = arr[i];
	}
	return arr2;
}