#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MX 50005
long long npos, rpos, gpos, n, m, mod = 1e9;
long long dfn[MX], low[MX], rec[MX], g[MX], sz[MX], dp[MX], ind[MX], vis2[MX], vis1[MX];
vector<int> to[MX], rto[MX];
queue<int> q;
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
    if (low[now] == dfn[now])
    {
        gpos++;
        for (int i = rpos; i >= 1; i--)
        {
            g[rec[i]] = gpos, sz[gpos]++;
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
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v);
        rto[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    q.push(1), vis1[1] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : to[now])
        {
            if (vis1[nxt] == 0)
            {
                q.push(nxt), vis1[nxt] = 1;
            }
            ind[nxt]++; // 只看从1出发的入度
        }
    }
    q.push(2), vis2[2] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : rto[now])
        {
            if (vis2[nxt] == 0)
            {
                q.push(nxt), vis2[nxt] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis1[i] && vis2[i] && sz[g[i]] > 1)
        {
            cout << "inf" << endl;
            return 0;
        }
    }
    q.push(1), dp[1] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : to[now])
        {
            dp[nxt] = (dp[nxt] + dp[now]) % mod;
            if (--ind[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    cout << dp[2] << endl;
    return 0;
}