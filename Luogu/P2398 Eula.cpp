#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
int prim[MX], vis[MX], pos, n;
long long phi[MX], ans;
int main()
{
    cin >> n;
    vis[0] = vis[1] = phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pos && i * prim[j] <= n; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] != 0)
            {
                phi[i * prim[j]] = phi[i] * (prim[j] - 1);
            }
            else
            {
                phi[i * prim[j]] = phi[i] * prim[j];
                break;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        phi[i] += phi[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (phi[n / i] * 2 - 1) * i;
    }
    cout << ans << endl;
    return 0;
}
// 设 f[x] = gcd为x的数对个数，则 ans = f[1] * 1 + f[2] * 2 + ... + f[n] * n
// 如果有数对 a,b 的 gcd(a, b) = 1，则数对 ax, bx 的 gcd(ax, bx) = x
// 所以 f[x] = gcd(a,b)为1的数对数量 (a, b <= n / x) 也就是互质的数对数量
// f[x] = Σ φ(k) * 2 - 1  (k∈[1, n / x])，因为假如 a,b 互质那么可以形成 a,b 和 b,a，其中 1,1 除外