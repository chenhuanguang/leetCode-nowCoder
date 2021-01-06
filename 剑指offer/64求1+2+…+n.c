int sumNums(int n)
{ 
    //短路求值
    //n > 0 计算 n+=sumNums(n - 1)
    //n = 0 不计算并执行下一条语句
    bool b = n && (n+=sumNums(n - 1));
    return n;
}