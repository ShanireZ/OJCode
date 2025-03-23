#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << '-';
        }
        cout << '=';
        for (int i = 1; i <= n / 2; i++)
        {
            cout << '-';
        }
    }
    else
    {
        for (int i = 1; i < n / 2; i++)
        {
            cout << '-';
        }
        cout << "==";
        for (int i = 1; i < n / 2; i++)
        {
            cout << '-';
        }
    }
    return 0;
}