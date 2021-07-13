class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            int cnt = 0;
            for (auto& e:nums)
            {
                //获取每个位上的个数
                cnt += (e >> i) & 1;
            }
            //模3再右移i，表示该数原本应该在的位置，再或上之前的结果
            res |= (cnt % 3) << i;
        }
        return res;
    }
};