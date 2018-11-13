int maxProfit(int* prices, int pricesSize) {
    int max = 0, in = 0, out = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] >= prices[out]) //没有跌，买入或者继续持有股份
        {
            out = i;
        } else { //过票跌了
            if (out > in) //股票下跌卖出之前的股份 (in = out 代表没有买入观察中)
            {
                max = max + prices[out] - prices[in];
            }
            in = i;
            out = i;
        }
        
    }
    //最后一直涨，卖出全部股票
    if (out > in)
    {
        max = max + prices[out] - prices[in];
    }
    
    return max;
}