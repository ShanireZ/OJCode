#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long n, k, a[300005], ex[555], add[555];
int f(int x)
{
    return (x - 1) / k;
}
int main()
{
    cin >> n;
    k = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ex[f(i)] += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long opt, l, r, c;
        cin >> opt >> l >> r >> c;
        int fl = f(l), fr = f(r);
        if (opt)
        {
            long long ans = 0;
            if (fl == fr)
            {
                for (int j = l; j <= r; j++)
                {
                    ans += a[j] + add[fl];
                }
            }
            else
            {
                for (int j = l; j <= (fl + 1) * k; j++)
                {
                    ans += a[j] + add[fl];
                }
                for (int j = fl + 1; j < fr; j++)
                {
                    ans += ex[j];
                }
                for (int j = fr * k + 1; j <= r; j++)
                {
                    ans += a[j] + add[fr];
                }
            }
            cout << (ans % (c + 1) + (c + 1)) % (c + 1) << '\n';
        }
        else
        {
            if (fl == fr)
            {
                for (int j = l; j <= r; j++)
                {
                    a[j] += c, ex[fl] += c;
                }
            }
            else
            {
                for (int j = l; j <= (fl + 1) * k; j++)
                {
                    a[j] += c, ex[fl] += c;
                }
                for (int j = fl + 1; j < fr; j++)
                {
                    ex[j] += c * k, add[j] += c;
                }
                for (int j = fr * k + 1; j <= r; j++)
                {
                    a[j] += c, ex[fr] += c;
                }
            }
        }
    }
    return 0;
}