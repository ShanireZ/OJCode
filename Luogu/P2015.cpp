#include <cstring>
#include <iostream>
using namespace std;
int n, q, fa[105], dp[105][105], g[105][105];
void dfs(int now)
{
    for (int nxt = 1; nxt <= n; nxt++)
    {
        if (nxt == fa[now] || g[now][nxt] == -1)
        {
            continue;
        }
        fa[nxt] = now;
        dfs(nxt);
        for (int i = q; i > 0; i--)
        {
            for (int j = 0; j < i; j++) // now到nxt的边必然包含
            {
                dp[now][i] = max(dp[now][i], dp[now][i - 1 - j] + dp[nxt][j] + g[now][nxt]);
            }
        }
    }
}
int main()
{
    memset(g, -1, sizeof(g));
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    dfs(1);
    cout << dp[1][q] << endl;
    return 0;
}