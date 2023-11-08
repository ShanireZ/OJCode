#include <algorithm>
#include <iostream>
using namespace std;
#define MX 4000005
int vis[MX], prim[MX], pos, n;
long long phi[MX], ans[MX];
int main()
{
    phi[1] = 1;
    for (int i = 2; i <= 4000000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i, phi[i] = i - 1;
        }
        for (int j = 1; j <= pos && i * prim[j] <= 4000000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] != 0)
            {
                phi[i * prim[j]] = phi[i] * phi[prim[j]];
            }
            else
            {
                phi[i * prim[j]] = phi[i] * prim[j];
                break;
            }
        }
    }
    for (int i = 1; i <= 2000000; i++)
    {
        for (int j = i + i, p = 2; j <= 4000000; j += i, p++)
        {
            ans[j] += i * phi[p];
        }
    }
    for (int i = 1; i <= 4000000; i++)
    {
        ans[i] += ans[i - 1];
    }
    cin >> n;
    while (n)
    {
        cout << ans[n] << endl;
        cin >> n;
    }
    return 0;
}
// TAG: 数论 欧拉函数 UVA11424