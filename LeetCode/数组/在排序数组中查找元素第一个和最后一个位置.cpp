class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool flag)
    {
        int sz = nums.size();
        int left = 0;
        int right = sz - 1;
        int idx = sz;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (flag && nums[mid] >= target))
            {
                right = mid - 1;
                idx = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res;
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false) - 1;
        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
        {
            res.push_back(left);
            res.push_back(right);
            return res;
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};