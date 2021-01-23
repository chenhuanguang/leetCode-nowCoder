
bool isLongPressedName(char * name, char * typed)
{
    char* pn = name;
    char* pt = typed;

    while (*pn != '\0' && *pt != '\0')
    {
        int len = 0;
        while (*pn == *(pn+1))
        {
            len++;
            pn++;
        }
        if (*pn == *pt)
        {
            while (*pt == *pn)
            {
                pt++;
                len--;
            }
            if (len >= 0)
                return false;
        }
        else
        {
            return false;
        }
        pn++;
    }

    if (*pn)
    {
        return false;
    }
    
    char tmp = *(--pt);
    while (*pt)
    {
        if (*pt != tmp)
            return false;
        pt++;
    }

    return true;
}