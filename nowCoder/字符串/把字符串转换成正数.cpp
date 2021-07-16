class Solution {
public:
    bool isDigit(const char& c)
    {
        return c >= '0' && c <= '9';
    }
    int StrToInt(string str) 
    {
        int res = 0;
        int flag = 1;
        if (str[0] == '-')
        {
            flag = -1;
        }  
        for (int i = 0; i < str.size(); ++i)
        {
            if (isDigit(str[i]))
            {
                res *= 10;
                res += str[i] - '0';
            }
            else if (i != 0 && !isDigit(str[i]))
                return 0;
        }
        return res * flag;
    }
};