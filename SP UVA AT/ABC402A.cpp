#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    char ch;
    while(cin >> ch)
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            cout << ch;
        }
    }
    return 0;
}