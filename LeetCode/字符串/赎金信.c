bool canConstruct(char * ransomNote, char * magazine)
{
    if (ransomNote == NULL)
        return true;

    int len1 = strlen(ransomNote);
    int len2 = strlen(magazine);

    if (len1 > len2)
        return false;
    
    int hash[26] = {0};

    for (int i = 0; i < len2; ++i)
    {
        hash[magazine[i] - 'a']++;
    }

    for (int i = 0; i < len1; ++i)
    {
        //magazine字符串中不存在ransomNote[i]这个字母
        //或者ransomNote[i]这个字母比magazine同字母的个数多
        if (hash[ransomNote[i] - 'a'] == 0)
            return false;
        hash[ransomNote[i] - 'a']--;
    }
    return true;
}