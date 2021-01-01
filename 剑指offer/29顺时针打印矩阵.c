/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int **matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if( matrix == NULL || matrixSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
        
    int left = 0;
    int right = *matrixColSize - 1;
    int top = 0;
    int bottom = matrixSize - 1;
    int size = matrixSize * (*matrixColSize);
    int* arr = (int*)malloc(sizeof(int) * size);
    int idx = 0;
    *returnSize = size;

    while (1)
    {
        if (left > right)
            break;
        for (int i = left; i <= right; ++i)
        {
            arr[idx++] = matrix[top][i];
        }
        ++top;

        if (top > bottom)
            break;
        for (int i = top; i <= bottom; ++i)
        {
            arr[idx++] = matrix[i][right];
        }
        --right;

        if (left > right)
            break;
        for (int i = right; i >= left; --i)
        {
            arr[idx++] = matrix[bottom][i];
        }
        --bottom;

        if (top > bottom)
            break;
        for (int i = bottom; i >= top; --i)
        {
            arr[idx++] = matrix[i][left];
        }
        ++left;
 
    }
    
    return arr;
}