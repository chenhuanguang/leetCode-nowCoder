int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int** ret = (int**)malloc(sizeof(int*)*numRows);
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
    for(int i = 0;i<numRows; ++i)
    {
        ret[i] = (int*)malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = i+1;
        ret[i][0] = ret[i][i] = 1;
        for(int j = 1;j<i;++j)
        {
            ret[i][j] = ret[i-1][j-1]+ret[i-1][j];
        }
    }
    return ret;
}