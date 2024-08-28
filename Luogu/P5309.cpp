#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 200005
#define MX2 455
int n, m, len, blk[MX];
long long a[MX], sum[MX2], pre[MX2][MX2], mod = 1e9 + 7;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    len = pow(n, 0.5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        blk[i] = (i - 1) / len + 1;
        sum[blk[i]] = sum[blk[i]] + a[i];
    }
    while (m--)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            long long z;
            cin >> z;
            if (x >= len)
            {
                for (int i = y; i <= n; i += x)
                {
                    sum[blk[i]] += z, a[i] += z;
                }
            }
            else
            {
                for (int i = y; i <= x; i++)
                {
                    pre[x][i] += z;
                }
            }
        }
        else
        {
            long long res = 0;
            if (blk[x] == blk[y])
            {
                for (int i = x; i <= y; i++)
                {
                    res += a[i];
                }
            }
            else
            {
                for (int i = x; i <= blk[x] * len; i++)
                {
                    res += a[i];
                }
                for (int i = (blk[y] - 1) * len + 1; i <= y; i++)
                {
                    res += a[i];
                }
                for (int i = blk[x] + 1; i <= blk[y] - 1; i++)
                {
                    res += sum[i];
                }
            }
            for (int i = 1; i < len; i++)
            {
                int l = (x - 1) / i + 1, r = (y - 1) / i + 1;
                if (l <= r)
                {
                    res += (r - l) * pre[i][i];
                }
                l = (x - 1) % i, r = (y - 1) % i + 1;
                res += pre[i][r] - pre[i][l];
            }
            cout << res % mod << '\n';
        }
    }
    return 0;
}
// TAG: 根号分治 分块 前缀和