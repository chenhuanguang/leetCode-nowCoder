bool isPalindrome(char * s)
{
    int len = strlen(s);
    int head = 0;
    int tail = len - 1;
    
    while (head < tail)
    {
        //找到字符为数字或者字母的位置
       while(head < tail && !isalpha(s[head]) && !isdigit(s[head]))
        {
            head++;
        }
        while(head < tail && !isalpha(s[tail]) && !isdigit(s[tail]))
        {
            tail--;
        }
        //一个数字一个字母
        if (isalpha(s[head]) && isdigit(s[tail]) || (isalpha(s[tail]) && isdigit(s[head])))
        {
            return false;
        }
        if (s[head] == s[tail] || s[head] - 32 == s[tail] || s[head] + 32 == s[tail])
        {
            head++;
            tail--;
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}