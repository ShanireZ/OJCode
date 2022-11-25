#include <iostream>
using namespace std;
long long a[100005], b[100005], m, n, t, pos;
long long gcd(long long x, long long y)
{
    long long r = x % y;
    while (r)
    {
        x = y, y = r;
        r = x % y;
    }
    return y;
}
int main()
{
    cin >> t;
    while (t--)
    {
        int ok = 1;
        cin >> n >> m;
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 2; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                b[i] = gcd(a[i], a[i - 1]), pos = i;
                break;
            }
        }
        for (int i = pos - 1; i >= 1; i--)
        {
            b[i] = a[i] / b[i + 1];
            if (b[i] > m)
            {
                ok = 0;
            }
        }
        for (int i = pos + 1; i <= n; i++)
        {
            b[i] = a[i - 1] / b[i - 1];
            if (b[i] > m)
            {
                ok = 0;
            }
        }
        if (ok)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << b[i] << " ";
            }
            cout << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}