bool halvesAreAlike(char * s)
{
    char a[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '\0'};
    int len = strlen(s);
    int total1 = 0;
    int total2 = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < strlen(a); ++j)
        {
            if (s[i] == a[j] && i < len / 2)
            {
                total1++;
                break;
            }
            else if (s[i] == a[j] && i >= len / 2)
            {
                total2++;
                break;
            }
        }
    }

    return total1 == total2;
}