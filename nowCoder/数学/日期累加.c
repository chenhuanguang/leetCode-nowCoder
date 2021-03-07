#include <iostream>
using namespace std;

int isDay(int year, int month)
{
    static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day = days[month];
    if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0))
    {
        ++day;
    }
    return day;
}

int main()
{
    int m = 0;
    int year, month, day, n;
    cin >> m;
    while(m--)
    {
        cin >> year >> month >> day >> n;
        day += n;
        while (day > isDay(year, month))
        {
            day -= isDay(year, month);
            ++month;
            if (month == 13)
            {
                month = 1;
                ++year;
            } 
        }
        printf("%d-%02d-%02d\n",year, month, day);
    }
    return 0;
}