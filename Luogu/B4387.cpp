#include <algorithm>
#include <iostream>
using namespace std;
long long n, q, pt[105][105], zz[105][105];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> pt[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> zz[i][j];
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        long long ans = 1e18;
        if (pt[u][v] != -1)
        {
            ans = min(ans, pt[u][v]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (zz[u][i] != -1 && zz[i][v] != -1)
            {
                ans = min(ans, zz[u][i] + zz[i][v]);
            }
        }
        cout << (ans != 1e18 ? ans : -1) << endl;
    }
    return 0;
}