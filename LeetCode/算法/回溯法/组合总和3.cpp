class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int n, int start, int sum)
    {
        if (path.size() == k)
        {
            if (sum == n)
                res.push_back(path);    
            return;
        }
        if (sum > n)
            return;

        for (int i = start; i <= 9 - (k - path.size()) + 1; ++i)
        {
            sum += i;
            path.push_back(i);
            backtracking(k, n, ++start, sum);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        res.clear();
        path.clear();
        backtracking(k, n, 1, 0);
        return res;
    }
};