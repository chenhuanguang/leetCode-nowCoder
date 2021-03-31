int max(int a, int b)
{
    return a > b ? a : b;
}

int maxValue(int** grid, int gridSize, int* gridColSize)
{
    for (int i = 1; i < gridSize; ++i)
    {
        grid[i][0] += grid[i - 1][0];
    }
    for (int j = 1; j < *gridColSize; ++j)
    {
        grid[0][j] += grid[0][j - 1];
    }
    for (int i = 1; i < gridSize; ++i)
    {
        for (int j = 1; j < *gridColSize; ++j)
        {
            grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[gridSize-1][*gridColSize-1];
}