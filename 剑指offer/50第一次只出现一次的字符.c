char firstUniqChar(char* s)
{
    int* hash = (int*)calloc(123, sizeof(int));
    char *p = s;
    while(*p != '\0')
    {
        hash[*p]++;
        p++;
    }

    while(*s != '\0')
    {
        if (hash[*s] == 1)
        {
            return *s;
        }
        s++;
    }

    return ' ';
}