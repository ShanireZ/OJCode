#include <algorithm>
#include <iostream>
using namespace std;
long long prim[10005], cnt[10005], vis[10005], tot, pos, n, m;
int main()
{
    for (int i = 2; i <= 10000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= 10000; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        tot += x;
        for (int k = x; k > 1; k--)
        {
            long long tmp = k;
            for (int j = 1; j <= pos && tmp > 1; j++)
            {
                while (tmp % prim[j] == 0)
                {
                    cnt[j]--, tmp /= prim[j];
                }
            }
        }
    }
    if (tot > n)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int k = n; k > n - tot; k--)
    {
        long long tmp = k;
        for (int j = 1; j <= pos && tmp > 1; j++)
        {
            while (tmp % prim[j] == 0)
            {
                cnt[j]++, tmp /= prim[j];
            }
        }
    }
    long long ans = 1, mod = 10007;
    for (int i = 1; i <= pos; i++)
    {
        for (int j = 1; j <= cnt[i]; j++)
        {
            ans = ans * prim[i] % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 质因数分解 质数 组合数学