#include <iostream>
using namespace std;
#define MX 5005
int n, epos, pre[MX * 2], to[MX * 2], last[MX], sz[MX], fa[MX];
long long f[MX], dp[MX][MX];
void addEdge(int u, int v, int eid)
{
    pre[eid] = last[u], to[eid] = v;
    last[u] = eid;
}
void dfs(int now)
{
    sz[now] = 1, dp[now][1] = 0;
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt == fa[now])
        {
            continue;
        }
        fa[nxt] = now;
        dfs(nxt);
        for (int j = sz[now] + sz[nxt]; j >= 1; j--)
        {
            dp[now][j] = 0x3f3f3f3f3f3f3f3f; // 有新成员加入,数据重新统计
            // 此处需要剪枝:根节点最多提供sz[now],新枝至少需要提供j-sz[now]
            for (int k = max(1, j - sz[now]); k <= sz[nxt] && j - k >= 1; k++)
            {
                dp[now][j] = min(dp[now][j], dp[now][j - k] + dp[nxt][k]);
            }
        }
        sz[now] += sz[nxt];
    }
    dp[now][sz[now]] = 0;
    for (int i = sz[now]; i > 1; i--)
    {
        dp[now][1] = min(dp[now][1], dp[now][i] + f[i - 1]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> f[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, ++epos);
        addEdge(v, u, ++epos);
    }
    dfs(1);
    cout << dp[1][1] << endl;
    return 0;
}