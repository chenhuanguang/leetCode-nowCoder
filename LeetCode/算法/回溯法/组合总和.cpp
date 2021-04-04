class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int flag = 1;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
    {
        if (sum > target)
            return ;
        if (sum == target)
        {
            res.push_back(path);
            return ;
        }    

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};