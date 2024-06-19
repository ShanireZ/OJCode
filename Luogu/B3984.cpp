#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long x, y;
    cin >> x >> y;
    if ((y - x) % 2 == 1)
    {
        cout << (y - x) / 2 + 1 << endl;
    }
    else
    {
        cout << (y - x) / 2 << endl;
    }
    return 0;
}