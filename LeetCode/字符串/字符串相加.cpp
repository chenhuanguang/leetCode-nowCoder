class Solution {
public:
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

            if (curSum > 9)
            {
                step = 1;
                curSum -= 10;
            }
            else
            {
                step = 0;
            }

            //ret.insert(0, 1, curSum + '0');
            ret += curSum + '0';
        }

        if (step == 1)
        {
            //ret.insert(0, 1, 1 + '0');
            ret += '1';
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};