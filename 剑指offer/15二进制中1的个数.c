int hammingWeight(uint32_t n) 
{
    int num = 0;
    while(n != 0)
    {
        n&=(n - 1);
        ++num;
    }
    return num;
}