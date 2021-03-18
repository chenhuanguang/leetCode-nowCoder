int numJewelsInStones(char * jewels, char * stones)
{
    if (jewels == NULL)
    {
        return 0;
    }
    if (stones == NULL)
    {
        return 0;
    }
    int res = 0;
    char *tmp = jewels;
    while (*stones != '\0')
    {
        tmp = jewels;
        while (*tmp != '\0')
        {
            if (*stones == *tmp)
            {
                ++res;
                break;
            }
            tmp++;
        }
        stones++;
    }
    return res;
}