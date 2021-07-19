#include <iostream>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        int* hash = new int[123];
        for (int i = 0; i < str.size(); ++i)
        {
            hash[str[i]]++;
        }
        int i;
        for (i = 0; i < str.size(); ++i)
        {
            if (hash[str[i]] == 1)
            {
                cout << str[i] << endl;
                break;
            }
        }
        if (i == str.size())
            cout << -1 <<endl;
        
    }
    return 0;
}