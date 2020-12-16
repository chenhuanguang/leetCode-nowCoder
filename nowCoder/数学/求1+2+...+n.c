class Sum
{
public:
    Sum()
    {
        _sum+=_i;
        ++_i;
    }
    ~Sum()
    {
        _sum = 0;
        _i = 1;
    }
    static int GetSum()
    {
        return _sum;
    }
private:
    static int _i;
    static int _sum;
};
 
int Sum::_i = 1;
int Sum::_sum = 0;
 
class Solution {
public:
    
    int Sum_Solution(int n) {
        Sum a[n];
        return Sum::GetSum();
    }
};