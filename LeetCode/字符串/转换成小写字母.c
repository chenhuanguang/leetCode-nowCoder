char * toLowerCase(char * str)
{
    if (str == NULL)
    {
        return NULL;
    }

    char *pstr = str;

    while(*pstr != '\0')
    {
        if (*pstr <= 'Z' && *pstr >= 'A')
        {
            *pstr = *pstr + 32;
        }
        ++pstr;
    }

    return str;
}