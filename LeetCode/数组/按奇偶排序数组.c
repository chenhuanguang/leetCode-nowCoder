int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
     *returnSize = ASize;
    if (A == NULL || ASize < 2)
        return A;
    
    int head = 0;
    int tail = ASize - 1;

    while (head < tail)
    {
        while (head < tail && A[head] % 2 == 0)
        {
            ++head;
        }

        while (head < tail && A[tail] % 2 != 0)
        {
            --tail;
        }

        int tmp = A[head];
        A[head] = A[tail];
        A[tail] = tmp;
    }

   
    return A;
}