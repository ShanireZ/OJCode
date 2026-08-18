#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long n, k, a[300005], ex[555];
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
    }
    for (int i = 1; i <= n; i++)
    {
        long long opt, l, r, c;
        cin >> opt >> l >> r >> c;
        if (opt == 0)
        {
            int fl = f(l), fr = f(r);
            if (fl == fr)
            {
                for (int j = l; j <= r; j++)
                {
                    a[j] += c;
                }
            }
            else
            {
                for (int j = l; j <= (fl + 1) * k; j++)
                {
                    a[j] += c;
                }
                for (int j = fl + 1; j < fr; j++)
                {
                    ex[j] += c;
                }
                for (int j = fr * k + 1; j <= r; j++)
                {
                    a[j] += c;
                }
            }
        }
        else
        {
            cout << a[r] + ex[f(r)] << '\n';
        }
    }
    return 0;
}