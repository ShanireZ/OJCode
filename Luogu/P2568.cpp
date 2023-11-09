#include <iostream>
using namespace std;
long long prim[10000005], vis[10000005], phi[10000005], ans, n, pos;
int main()
{
    cin >> n;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i, phi[i] = i - 1;
        }
        for (int j = 1; j <= pos && prim[j] * i <= n; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] != 0)
            {
                phi[prim[j] * i] = phi[i] * (prim[j] - 1);
            }
            else
            {
                phi[prim[j] * i] = phi[i] * prim[j];
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        phi[i] += phi[i - 1];
    }
    for (int i = 1; i <= pos; i++)
    {
        int num = prim[i];
        ans += phi[n / num] * 2 - 1;
    }
    cout << ans << endl;
    return 0;
}