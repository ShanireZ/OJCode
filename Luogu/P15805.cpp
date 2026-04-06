#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, mod = 1e9, es[105][105], g[105][105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            es[i][j] = 1e9;
        }
        es[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u][v] = min(es[u][v], w);
        es[v][u] = min(es[v][u], w);
    }
    for (int l = 1; l <= n; l++)
    {
        for (int r = l + 1; r <= n; r++)
        {
            for (int i = l; i <= r; i++)
            {
                for (int j = l; j <= r; j++)
                {
                    g[i][j] = es[i][j];
                }
            }
            for (int k = l; k <= r; k++)
            {
                for (int i = l; i <= r; i++)
                {
                    for (int j = l; j <= r; j++)
                    {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
            for (int i = l; i <= r; i++)
            {
                for (int j = i + 1; j <= r; j++)
                {
                    ans = (ans + g[i][j]) % mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}