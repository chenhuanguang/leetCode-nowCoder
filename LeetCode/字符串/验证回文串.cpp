class Solution {
public:
    bool isLetterDigit(const char& ch)
    {
        return ch >= '0' && ch <='9'
            || ch >='A' && ch <= 'Z'
            || ch >= 'a' && ch <= 'z';
    }

    bool isLetter(const char& ch)
    {
        return ch >='A' && ch <= 'Z';
    }

    bool isPalindrome(string s) 
    {
        for (auto& ch :s)
        {
            if (isLetter(ch))
            {
                ch += 32;
            }
        }
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isLetterDigit(s[begin]))
            {
                ++begin;
            }
            while (begin < end && !isLetterDigit(s[end]))
            {
                --end;
            }
            
            if (s[begin] != s[end])
                return false;

            ++begin;
            --end;
        }

        return true;
    }
};