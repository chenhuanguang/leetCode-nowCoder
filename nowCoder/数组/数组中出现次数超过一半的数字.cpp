class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        int sz = numbers.size();
        if (sz == 0)
            return 0;
        if (sz == 1 || sz == 2)
            return numbers[0];
        vector<int> nums(sz, 0);
        for (int i = 0; i < sz; ++i)
        {
            nums[numbers[i]]++;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > sz/2)
                return i;
        }
        return 0;
    }
};