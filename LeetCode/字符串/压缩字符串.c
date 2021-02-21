int compress(char* chars, int charsSize)
{
    int left = 0;
    int right = 1;
    int res = 0;
    while (left < charsSize)
    {
        int count = 1;
        //找到下一个不同的字母的索引
        while (right < charsSize && chars[left] == chars[right])
        {
            ++count;
            ++right;
        }

        if (count > 1 && count < 10)
        {
            chars[++res] = count + '0';
            left = right;
        }
        else if (count > 9 && count < 100)
        {
            chars[++res] = count / 10 + '0';
            chars[++res] = count % 10 + '0';
            left = right;
        }
        else if (count > 99 && count < 1000)
        {
            chars[++res] = count / 100 + '0';
            chars[++res] = count % 100 / 10 + '0';
            chars[++res] = count % 100 % 10 + '0';
            left = right;
        }
        else if (count >= 1000)
        {
            chars[++res] = 1 + '0';
            chars[++res] = 0 + '0';
            chars[++res] = 0 + '0';
            chars[++res] = 0 + '0';
            left = right;
        }
        //字母个数为1不用压缩
        else
        {
            ++left;
        }
        //更新字母索引位置，使其指向下一个字母的位置
        ++res;
        if (right < charsSize)
            chars[res] = chars[right++]; //更新当前要计数的字母
    }
    return res;
}