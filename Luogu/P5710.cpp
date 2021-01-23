#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x1 = 0, x2 = 0;
    if (n % 2 == 0)
    {
        x1 = 1;
    }
    if (n > 4 && n <= 12)
    {
        x2 = 1;
    }
    if (x1 == 1 && x2 == 1)
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 0 << " ";
    }
    if (x1 == 1 || x2 == 1)
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 0 << " ";
    }
    if (x1 == 1 ^ x2 == 1)
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 0 << " ";
    }
    if (x1 == 0 && x2 == 0)
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 0 << " ";
    }
    return 0;
}