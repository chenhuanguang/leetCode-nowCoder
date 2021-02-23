int lengthOfLongestSubstring(char* s)
{
    int len = strlen(s);
    if (len == 0)
        return 0;
    int hash[128] = {0};
    int left = 0;
    int res = 1;
    for (int right = 0; right < len; ++right)
    {
        ++hash[s[right]];
        while (hash[s[right]] >= 2)
        {
            --hash[s[left]];
            ++left;
        }
        res = fmax(res, right - left + 1);
    }

    return res;
}