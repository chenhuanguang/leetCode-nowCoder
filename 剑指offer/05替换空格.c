char* replaceSpace(char* s)
{
    if (s == NULL)
    {
        return NULL;
    }
    char* ret = (char*)malloc(strlen(s)*3*sizeof(s));

    int i = 0;
    while(*s != '\0')
    {
        if(*s == ' ')
        {
            ret[i++] = '%';
            ret[i++] = '2';
            ret[i++] = '0';
        }
        else
        {
            ret[i++] = *s;
        }
        ++s;
    }
    ret[i] = '\0';
   return ret;
}