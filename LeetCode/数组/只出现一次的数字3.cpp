class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {

        vector<int> res(2, 0);
        int a = 0;
        int pos;
        for (const auto& e : nums)
        {
            //两个只出现一次的元素的异或结果
            a ^= e;
        }
        for (int i = 0; i < 32; ++i)
        {
            if ((a >> i) & 1 == 1)
            {
                //异或前不一样的位置
                pos = i;
                break;
            }    
        }
        for (const auto& e : nums)
        {
            if ((e >> pos) &1 == 1)
                res[0] ^= e;
            else
                res[1] ^= e;
        }
        return res;
    }
};