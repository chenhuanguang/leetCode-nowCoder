int lengthOfLastWord(char * s)
{
    int len = strlen(s);
    int res = 0;
    if (len == 0)
        return 0;

    for (int i = len - 1; i >= 0; --i)
    {
        if (s[i] != ' ')
            res++;
        if (s[i] == ' ' && res)
            break;
    }

    return res;
}