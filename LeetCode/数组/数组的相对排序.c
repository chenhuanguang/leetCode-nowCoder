/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){

	int k = 0;
	for (int i = 0; i < arr2Size; i++)
	{
		for (int j = k; j < arr1Size; j++)
		{
			if (arr1[j] == arr2[i])
			{
				int temp = arr1[k];
				arr1[k] = arr1[j];
				arr1[j] =temp;
				k++;
			}
		}
	}

	// k=9
	for (int i = k; i < arr1Size; i++)
	{
		for (int j = k; j < arr1Size+k-i-1; j++)
		{
			if (arr1[j]>arr1[j + 1])
			{
				int temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}
    * returnSize = arr1Size;
	return arr1;
}