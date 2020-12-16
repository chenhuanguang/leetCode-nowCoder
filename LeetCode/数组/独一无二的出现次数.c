int int_qsort(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

bool uniqueOccurrences(int* arr, int arrSize)
{
	int j = 0;
	int flag = 0;
	qsort(arr, arrSize, sizeof(int), int_qsort);

	if (arrSize == 2)
	{
		if (arr[0] != arr[1])
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	for (int i = 0; i < arrSize; i++)
	{
		if (i == arrSize - 1 )
		{
			arr[j++] = i - flag + 1;
			break;
		}
		if (arr[i] != arr[i + 1])
		{
			arr[j++] = i - flag + 1;	 ///1 1 1 2 2 3 3
			flag = i + 1;
		}
	
	}
	qsort(arr, j, sizeof(int), int_qsort);
	for (int i = 0; i < j - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			return false;
		}
	}

	return true;
}