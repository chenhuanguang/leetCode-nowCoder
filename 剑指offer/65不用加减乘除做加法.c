
int add(int a, int b)
{
   
    while(b != 0)
    {
        int tmp = (a ^ b); //无进位的计算
        b = (size_t)(a & b) << 1; //进位计算
        a = tmp; //因为最后要相加，要到＋好，所以要重复此步骤。直到无进位（b = 0）
    }
    return a;
}