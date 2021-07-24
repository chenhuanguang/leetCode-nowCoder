#include<iostream>
using namespace std;

int isDay(int year, int month)
{
    static int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = days[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) 
    {
        ++day;
    }
    return day;
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int y1, m1, d1, y2, m2, d2, res;
    res = 1;
    int date1, date2;
    cin >> date1;
    cin >> date2;
    y1 = date1 / 10000;
    y2 = date2 / 10000;
    m1 = date1 / 100 % 100;
    m2 = date2 / 100 % 100;
    d1 = date1 % 100;
    d2 = date2 % 100;
    if (date1 > date2)
    {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }

    while (!(y1 == y2 && m1 == m2 && d1 == d2))
    {
        ++d1;
        if (d1 > isDay(y1, m1))
        {
            d1 = 1;
            ++m1;
            if (m1 == 13)
            {
                m1 = 1;
                ++y1;
            }
        }
        ++res;    
    }
    printf("%d\n",res);
    return 0;
}