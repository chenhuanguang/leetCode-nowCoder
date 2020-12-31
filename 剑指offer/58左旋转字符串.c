void Reverse(char *str, int pos, int pos2)
{
    while(pos < pos2)
    {
        char tmp = str[pos];
        str[pos] = str[pos2];
        str[pos2] = tmp;
        ++pos;
        --pos2;
    }
}

char* reverseLeftWords(char* s, int n)
{
    if(s == NULL)
    {
        return NULL;
    }

    int size = strlen(s);
    int k = n%size;
    
    Reverse(s, 0, k-1);
    Reverse(s, k, size-1);
    Reverse(s, 0, size-1);

    return s;
}