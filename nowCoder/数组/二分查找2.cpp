class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) 
    {
        // write code here
        int sz = nums.size();
        int left = 0;
        int right = sz -1;
        int mid;
        if (sz <= 0)
            return -1;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        
        if (nums[left] != target)
            return -1;
        return left;
    }
};