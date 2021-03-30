class Solution {
public:
    const string lettersmap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector<string> res;
    string str;
    void backtracking(string& digits, int idx)
    {
        if (idx == digits.size())
        {
            res.push_back(str);
            return;
        }

        int digit = digits[idx] - '0';
        string lettes = lettersmap[digit];
        for (int i = 0; i < lettes.size(); ++i)
        {
            str.push_back(lettes[i]);
            backtracking(digits, idx + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        res.clear();
        str.clear();
        if (digits.empty())
            return res;
        backtracking(digits, 0);
        return res;
    }
};