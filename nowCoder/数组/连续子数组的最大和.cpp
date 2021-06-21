class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int res = array[0];
        for (int i = 1; i < array.size(); ++i)
        {
            //大于0就加
            array[i] += max(array[i - 1], 0);
            res = max(array[i], res);
        }
        return res;
    }
};