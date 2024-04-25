#include <algorithm>
#include <iostream>
using namespace std;
int vis[1000005], vis2[1000005], prim[1000005], pos, n, b, ans;
int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= 1000000; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    cin >> n >> b;
    int p = upper_bound(prim + 1, prim + pos + 1, b) - prim;
    for (int i = p; i <= pos; i++) // 将n范围内，所有大于b的质数及倍数标记
    {
        for (int j = prim[i]; j <= n; j += prim[i])
        {
            vis2[j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis2[i] == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}