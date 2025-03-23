#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int y = 1; y <= 2025; y++)
    {
        if ((x & y) + (x | y) == 2025)
        {
            cout << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}