#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, a, b;
        cin >> x >> a >> b;
        if (a == 0)
        {
            cout << -b << endl;
        }
        else if (a == 1)
        {
            if (b == 0)
            {
                cout << x << endl;
            }
            else
            {
                cout << x % b - b << endl;
            }
        }
        else
        {
            long long r = x * a - b - x;
            while (x >= 0 && r < 0)
            {
                x += r;
                r *= a;
            }
            cout << x << endl;
        }
    }
    return 0;
}