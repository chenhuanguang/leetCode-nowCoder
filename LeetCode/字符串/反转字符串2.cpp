class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int len = s.size();
        int begin = 0;
        while (begin < len)
        {
            int tmp1 = begin;//起始的交换位置
            int tmp2 = begin + k - 1; //要交换的最后一个位置
            if (k > len - begin)//剩余字符少于 k 个，将剩余字符全部反转
            {
                tmp2 = --len;
            }
            while (tmp1 < tmp2)
            {
                swap(s[tmp1], s[tmp2]);
                ++tmp1;
                --tmp2;
            }
            //更新begin
            begin =begin + 2*k;
        }
        return s;
    }
};