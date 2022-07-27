#include <cstring>
#include <iostream>
using namespace std;
int n, q, ans, fa[105], g[105][105], dp[105][105];
void dfs(int now)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == now || fa[now] == i || g[now][i] == -1)
        {
            continue;
        }
        fa[i] = now;
        dfs(i);
        for (int j = n - 1; j >= 1; j--) // now子树一共保留j条边
        {
            for (int k = 0; k <= j - 1; k++) // i子树一共保留k条边 还有条now到i的边
            {
                dp[now][j] = max(dp[now][j], g[now][i] + dp[i][k] + dp[now][j - k - 1]);
            }
        }
    }
}
int main()
{
    cin >> n >> q;
    memset(g, -1, sizeof(g));
    for (int i = 1; i < n; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = w;
    }
    dfs(1);
    cout << dp[1][q] << endl;
    return 0;
}