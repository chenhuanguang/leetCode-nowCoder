class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backstracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i)
        {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) 
            { 
                continue; 
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backstracking(candidates, target, sum, i +1, used);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        res.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backstracking(candidates, target, 0, 0, used);
        return res;
    }
};