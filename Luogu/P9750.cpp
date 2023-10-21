#include <algorithm>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int t = (b < 0 ? -1 : 1);
    a = abs(a), b = abs(b);
    while (a % b != 0)
    {
        int r = a % b;
        a = b, b = r;
    }
    return b * t;
}
int main()
{
    int T, lim;
    cin >> T >> lim;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int d = b * b - 4 * a * c;
        if (d < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else if (d == 0)
        {
            int x = -b, y = a + a;
            int g = gcd(x, y);
            x /= g, y /= g;
            cout << x;
            if (y != 1)
            {
                cout << "/" << y;
            }
            cout << endl;
            continue;
        }
        int x2 = (a < 0 ? -1 : 1), y2 = a + a;
        for (int i = 2236; i >= 2; i--)
        {
            if (d % (i * i) == 0)
            {
                x2 *= i, d /= (i * i);
            }
        }
        int g = gcd(x2, y2);
        x2 /= g, y2 /= g;
        int x1 = -b, y1 = a + a;
        g = gcd(x1, y1);
        x1 /= g, y1 /= g;
        if (d == 1) // 解是有理数
        {
            int x = x1 * y2 + x2 * y1, y = y1 * y2;
            g = gcd(x, y);
            x /= g, y /= g;
            cout << x;
            if (y != 1)
            {
                cout << "/" << y;
            }
            cout << endl;
        }
        else // 解是无理数
        {
            if (x1 != 0)
            {
                cout << x1;
                if (y1 != 1)
                {
                    cout << "/" << y1;
                }
                cout << "+";
            }
            if (x2 != 1)
            {
                cout << x2 << "*";
            }
            cout << "sqrt(" << d << ")";
            if (y2 != 1)
            {
                cout << "/" << y2;
            }
            cout << endl;
        }
    }
    return 0;
}