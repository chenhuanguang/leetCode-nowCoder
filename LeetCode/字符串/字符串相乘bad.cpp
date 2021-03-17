class Solution {
public:
    string multiply(string num1, string num2)
    {
        if (num1[0] == '0' || num2[0] == '0')
        {
            return "0";
        }
        string res;
        int len1 = num1.size() - 1;
        int len2 = num2.size() - 1;
        int len3 = num2.size();
        string* str = new string[len3];
        int idx = 0;
        while (len2 >= 0)
        {
            int step = 0;//进位
            int val2 = num2[len2--] - '0';
            int tmp1 = len1;

            while (tmp1 >= 0)
            {
                int sum = 0;
                int val1 = num1[tmp1--] - '0';
                sum = step + val1 * val2;
                if (sum > 9)
                {
                    step = sum / 10;
                    sum = sum % 10;
                }
                else
                {
                    step = 0;
                }
                str[idx] += sum + '0';
            }
            if (step != 0)//最高位进位
            {
                str[idx] += step + '0';
            }
            int tmp = idx;
            reverse(str[idx].begin(), str[idx].end());
            while (tmp--) //补0
            {
                str[idx] += '0';
            }
            idx++;
        }

        string tmp;
        for (int i = 0; i < len3; ++i)
        {
            tmp = addStrings(tmp, str[i]);
            res = tmp;
        }
        return res;
    }

    //字符串相加
        string addStrings(string num1, string num2) 
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string ret;
        int step = 0;

        while (end1 >= 0 || end2 >= 0)
        {
            int curSum = step;
            if (end1 >= 0)
            {
                curSum += num1[end1--] - '0';
            }
            if (end2 >= 0)
            {
                curSum += num2[end2--] - '0';
            }
            step = curSum/10;
            curSum = curSum%10;
            ret += curSum + '0';
        }

        if (step == 1)
        {
            ret += '1';
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};