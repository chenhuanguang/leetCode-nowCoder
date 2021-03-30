class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void backtracking(int n, int k, int start)
    {
        if (tmp.size() >= k)
        {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i <= n - (k - tmp.size()) + 1; ++i)
        {
            tmp.push_back(i);
            backtracking(n, k, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        res.clear();
        tmp.clear();
        backtracking(n, k, 1);
        return res;
    }
};