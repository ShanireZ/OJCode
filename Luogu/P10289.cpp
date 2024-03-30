#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MX 200005
queue<int> q;
vector<int> to[MX];
int n, k, m, trans[MX], dp[MX], anc[MX][20];
void dfs(int now)
{
    dp[now] = dp[anc[now][0]] + 1;
    for (int i = 1; i <= 18; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : to[now])
    {
        if (nxt == anc[now][0])
        {
            continue;
        }
        anc[nxt][0] = now, dfs(nxt);
    }
}
int lca(int a, int b)
{
    if (dp[a] < dp[b])
    {
        swap(a, b);
    }
    for (int i = 18; i >= 0; i--)
    {
        if (dp[anc[a][i]] >= dp[b])
        {
            a = anc[a][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 18; i >= 0; i--)
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i], b = anc[b][i];
        }
    }
    return anc[a][0];
}
int main()
{
    ios::sync_with_stdio(0);
    memset(trans, 0x3f, sizeof(trans));
    cin >> n >> k >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        q.push(x), trans[x] = 0;
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : to[now])
        {
            if (trans[nxt] == 0x3f3f3f3f)
            {
                trans[nxt] = trans[now] + 1;
                q.push(nxt);
            }
        }
    }
    dfs(1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        int x = lca(a, b);
        cout << min(dp[a] + dp[b] - 2 * dp[x], trans[a] + trans[b]) << '\n';
    }
    return 0;
}