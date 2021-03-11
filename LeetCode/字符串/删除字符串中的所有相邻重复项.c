char * removeDuplicates(char * S)
{
    int len = strlen(S);
    char *res = (char*)malloc(sizeof(char) * len);
    int idx = 0;
    for (int i = 0; i < len; ++i)
    {
        if (idx > 0 && res[idx - 1] == S[i])
        {
            --idx;
        }
        else
        {
            res[idx++] = S[i];
        }
    }
    res[idx] = '\0';
    return res;
}