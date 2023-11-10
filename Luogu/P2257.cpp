#include <iostream>
using namespace std;
#define MX 10000000
long long f[MX + 5], ms[MX + 5], prim[MX + 5], vis[MX + 5], pos, t;
int main()
{
    ms[1] = 1;
    for (int i = 2; i <= MX; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i, ms[i] = -1;
        }
        for (int j = 1; j <= pos && prim[j] * i <= MX; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] != 0)
            {
                ms[prim[j] * i] = -ms[i];
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        for (int j = 1; j * prim[i] <= MX; j++)
        {
            f[j * prim[i]] += ms[j];
        }
    }
    for (int i = 1; i <= MX; i++)
    {
        f[i] += f[i - 1];
    }
    cin >> t;
    while (t--)
    {
        long long ans = 0, n, m;
        cin >> n >> m;
        if (n > m)
        {
            swap(n, m);
        }
        int l = 1, r = 0;
        while (l <= n)
        {
            r = min(n / (n / l), m / (m / l));
            ans += (f[r] - f[l - 1]) * (n / l) * (m / l);
            l = r + 1;
        }
        cout << ans << endl;
    }
    return 0;
}