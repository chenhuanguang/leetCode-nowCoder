#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        size_t pos = str.rfind(' ');
        cout << str.size() - pos - 1 << endl;
    }
    return 0;
}