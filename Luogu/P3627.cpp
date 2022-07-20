#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MX 500005
queue<int> q;
int n, m, s, p, npos, gpos, spos, ans;
int dfn[MX], low[MX], g[MX], stk[MX], atm[MX], bar[MX], dp[MX], in[MX];
vector<int> to[MX], sto[MX];
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    stk[++spos] = now;
    for (int i = 0; i < to[now].size(); i++)
    {
        int t = to[now][i];
        if (dfn[t] == 0)
        {
            tarjan(t);
            low[now] = min(low[now], low[t]);
        }
        else if (g[t] == 0)
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
    if (dfn[now] == low[now])
    {
        gpos++;
        while (stk[spos] != now)
        {
            g[stk[spos--]] = gpos;
        }
        g[stk[spos--]] = gpos;
    }
}
void makescc()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < to[i].size(); j++)
        {
            int t = to[i][j];
            if (g[t] == g[i])
            {
                continue;
            }
            sto[g[i]].push_back(g[t]);
        }
    }
}
void SPFA()
{
    dp[g[s]] = atm[g[s]], in[g[s]] = 1;
    q.push(g[s]);
    while (q.size())
    {
        int f = q.front();
        q.pop(), in[f] = 0;
        for (int i = 0; i < sto[f].size(); i++)
        {
            int t = sto[f][i];
            if (dp[t] >= dp[f] + atm[t])
            {
                continue;
            }
            dp[t] = dp[f] + atm[t];
            if (in[t] == 0)
            {
                in[t] = 1, q.push(t);
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
        to[u].push_back(v);
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
        int x;
        cin >> x;
        atm[g[i]] += x;
    }
    cin >> s >> p;
    for (int i = 1; i <= p; i++)
    {
        int x;
        cin >> x;
        bar[g[x]] = 1;
    }
    makescc();
    SPFA();
    for (int i = 1; i <= gpos; i++)
    {
        if (bar[i] == 0)
        {
            continue;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}