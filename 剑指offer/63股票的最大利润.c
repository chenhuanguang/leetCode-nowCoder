int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize == 0 || pricesSize == 1)
    {
        return 0;
    }
    //卖出的价格
    int max = prices[pricesSize - 1];
    //利润
    int profit = 0;
    int res = 0;
    for (int i = pricesSize - 2; i >= 0; --i)
    {
        profit = max - prices[i];
        //利润小于等于0，说明前面的数更大，
        if (profit <= 0)
        {
            max = prices[i];
        }
        else if (profit > res)
        {
            res = profit;
        }
    }
    return res;
}