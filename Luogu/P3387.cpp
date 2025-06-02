#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MX 10005
queue<int> q;
vector<int> to[MX], nto[MX];
int n, m, cnt, npos, rpos, ans;
int v[MX], nv[MX], dfn[MX], low[MX], g[MX], rec[MX], ind[MX], dp[MX];
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    rec[++rpos] = now;
    for (int nxt : to[now])
    {
        if (dfn[nxt] == 0)
        {
            tarjan(nxt);
            low[now] = min(low[now], low[nxt]);
        }
        else if (g[nxt] == 0)
        {
            low[now] = min(low[now], dfn[nxt]);
        }
    }
    if (low[now] == dfn[now]) //! 环头
    {
        cnt++;
        for (int i = rpos; i >= 1; i--)
        {
            g[rec[i]] = cnt;
            if (rec[i] == now)
            {
                rpos = i - 1;
                break;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x = g[i];
        nv[x] += v[i];
        for (int j : to[i])
        {
            int y = g[j];
            if (x != y)
            {
                nto[x].emplace_back(y), ind[y]++;
            }
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (ind[i] == 0)
        {
            q.emplace(i), dp[i] = nv[i];
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop(), ans = max(ans, dp[now]);
        for (int nxt : nto[now])
        {
            ind[nxt]--;
            dp[nxt] = max(dp[nxt], dp[now] + nv[nxt]);
            if (ind[nxt] == 0)
            {
                q.emplace(nxt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}