// bool isPalindrome(int x)
// {
//     if (x < 0)
//         return false;

//     int tmp = x;
//     int len = 0;
//     while (tmp != 0)
//     {
//         tmp /=10;
//         ++len;
//     }
//     int res = 0;
//     for (int i = 0; i < len / 2; ++i)
//     {
//         res = res * 10 + x % 10;
//         x /= 10;
//     }

//     if (len % 2 == 1)
//         x /= 10;
//     return res == x ? true : false;
// }

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int tmp = x;
    long res = 0;
    while (tmp != 0)
    {
        res = res * 10 + tmp % 10;
        tmp /= 10;
    }

    return res == x ? true : false;
}