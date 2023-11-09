#include <iostream>
using namespace std;
int vis[40005], prim[40005], phi[40005], pos, n;
int main()
{
    phi[1] = 1;
    for (int i = 2; i <= 40000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i, phi[i] = i - 1;
        }
        for (int j = 1; j <= pos && i * prim[j] <= 40000; j++)
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
    cin >> n;
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += phi[i];
    }
    cout << (n == 1 ? 0 : ans * 2 + 1) << endl; // ans*2-1+2 中间统计了2次需要-1，第0行与第0列需要+2
    return 0;
}