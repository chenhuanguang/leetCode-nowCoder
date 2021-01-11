// int minArray(int* numbers, int numbersSize)
// {
//     for (int i = 1; i < numbersSize; ++i)
//     {
//         if (numbers[i] < numbers[i - 1])
//             return numbers[i];
//     }
//     return numbers[0];
// }

int minArray(int* numbers, int numbersSize)
{
    int left = 0;
    int right = numbersSize - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if (numbers[mid] > numbers[right])
        {
            left = mid + 1;
        }
        else if (numbers[mid] < numbers[right])
        {
            right = mid;
        }
        else
        {
            right-=1;
        }
    }
    return numbers[left];
}