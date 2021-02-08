void Swap(int *arr, int start, int end)
{
    --end;
    while (start < end)
    {
        arr[start] = arr[start] ^ arr[end];
        arr[end] = arr[start] ^ arr[end];
        arr[start] = arr[start] ^ arr[end];
        ++start;
        --end;
    }
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int cur = digitsSize -1;
    int idx = 0;
    int carry = 0;

    while (cur >= 0)
    {
        digits[cur] ++;
        if (digits[cur] > 9)
        {
            digits[cur--] = 0;
            res[idx++] = 0;
            carry = 1;
        }
        else
        {
            res[idx++] = digits[cur--];
            carry = 0;
            break;
        }
    }
    if (carry == 1)
    {
        res[idx++] = 1;
    }
    else
    {
        while(cur >= 0)
        {
            res[idx++] = digits[cur--];
        }
    }

    Swap(res, 0, idx);
    *returnSize = idx;
    return res;
}