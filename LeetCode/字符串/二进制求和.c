void reserve(char* str)
{
    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left;
        --right;
    }
}

char * addBinary(char * a, char * b)
{
    reserve(a);
    reserve(b);
    int len = (strlen(a) > strlen(b)) ? strlen(a) + 2 : strlen(b) + 2;
    int carry = 0;
    int idx = 0;
    char* res = (char*)malloc(sizeof(char) * len);
    for(int i = 0; i <len - 2; ++i)
    {
        carry += i < strlen(a) ? (a[i] == '1') : 0;
        carry += i < strlen(b) ? (b[i] == '1') : 0;
        res[idx++] = carry % 2 + '0';
        carry /= 2;
    }

    if (carry) {
        res[idx++] = '1';
    }
    res[idx] = '\0';
    reserve(res);

    return res;

}