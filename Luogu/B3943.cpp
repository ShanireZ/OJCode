#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    int delta = (y - x) / 2;
    if (delta <= 12000)
    {
        cout << 5 << endl;
    }
    else if (delta <= 18000)
    {
        cout << 6 << endl;
    }
    else if (delta <= 24000)
    {
        cout << 8 << endl;
    }
    else if (delta <= 36000)
    {
        cout << 11 << endl;
    }
    else
    {
        int x = ceil(delta / 48000.0);
        cout << 13 * x << endl;
    }
    return 0;
}