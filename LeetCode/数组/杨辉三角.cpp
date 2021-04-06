class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        //创建行
        vector<vector<int>> mat(numRows); 
        //创建列
        for (int i = 0; i < numRows; ++i)
        {
            mat[i].resize(i + 1);
        }

        for (int i = 0; i < numRows; ++i)
        {
            //一行中第一个和最后一个元素置为1
            mat[i][0] = mat[i][i] = 1;
            for (int j = 1; j < i; ++j)
            {
                mat[i][j] = mat[i - 1][j] + mat[i - 1][j - 1];
            }
        }
        return mat;
    }
};