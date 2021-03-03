int min(int a, int b)
{
    return a < b ? a : b;
}

int nthUglyNumber(int n)
{
    int *arr = (int*)malloc(sizeof(int) * n);
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    arr[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        arr[i] = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
        if (arr[i] == arr[p2] * 2)
            ++p2;
        if (arr[i] == arr[p3] * 3)
            ++p3;
        if (arr[i] == arr[p5] * 5)
            ++p5;
    }
    return arr[n - 1];
}