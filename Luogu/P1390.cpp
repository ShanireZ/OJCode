#include <algorithm>
#include <iostream>
using namespace std;
int n, pos, vis[2000005], prim[2000005];
long long ans, phi[2000005], f[2000005];
int main()
{
    cin >> n;
    phi[1] = 1;
    for (int i = 2; i <= 2000000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i, phi[i] = i - 1;
        }
        for (int j = 1; j <= pos && prim[j] * i <= 2000000; j++)
        {
            vis[prim[j] * i] = 1;
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
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i + i, p = 2; j <= 2000000; j += i, p++)
        {
            f[j] += i * phi[p];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}
// TAG: 数论 欧拉函数 UVA11424