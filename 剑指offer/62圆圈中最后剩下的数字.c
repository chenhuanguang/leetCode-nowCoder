int lastRemaining(int n, int m)
{
    if (n == 1) 
    {
        return 0;
    }
    int res = 0;

    for (int i = 2; i <= n; ++i)
    {
        res = (res + m) % i;
    }

    return res;
}