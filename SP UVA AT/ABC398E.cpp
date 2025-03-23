#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int h[105], g[105][105], n, sum;
void dfs(int now, int from, int dp)
{
    h[now] = dp;
    for (int nxt = 1; nxt <= n; nxt++)
    {
        if (from != nxt && g[now][nxt] == 1)
        {
            dfs(nxt, now, dp + 1);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            sum += ((h[i] + h[j]) % 2 && g[i][j] == 0);
        }
    }
    cout << (sum % 2 ? "First" : "Second") << endl;
    while (true)
    {
        if (sum % 2)
        {
            int ok = 1;
            for (int i = 1; i <= n && ok; i++)
            {
                for (int j = i + 1; j <= n && ok; j++)
                {
                    if ((h[i] + h[j]) % 2 && g[i][j] == 0)
                    {
                        g[i][j] = g[j][i] = 1, ok = 0;
                        cout << i << " " << j << endl;
                    }
                }
            }
        }
        else
        {
            int u, v;
            cin >> u >> v;
            if (u == -1 && v == -1)
            {
                return 0;
            }
            g[u][v] = g[v][u] = 1;
        }
        sum--;
    }
    return 0;
}