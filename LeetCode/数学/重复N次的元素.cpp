class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int ,int> m;
        for (const auto& e : nums)
            m[e]++;
        for (const auto& e : m)
        {
            if (e.second == nums.size() / 2)
                return e.first;
        }
        return -1;
    }
};