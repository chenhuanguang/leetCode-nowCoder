const MAX = 26;
int res;

void DFS(int* nums)
{
    for (int i = 0; i < MAX; ++i)
    {
        if (nums[i] <= 0)
        {
            continue;
        }
        nums[i]--;
        ++res;
        DFS(nums);
        ++nums[i];
    }
}

int numTilePossibilities(char * tiles)
{
    int* arr = (int*)calloc(MAX, sizeof(int));
    int len = strlen(tiles);
    res = 0;
    for (int i = 0; i < len; ++i)
    {
        arr[tiles[i] - 'A'] ++;
    }
    DFS(arr);
    return res;
}