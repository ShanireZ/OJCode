#include <iostream>
#include <set>
using namespace std;
int n, m, spos, gpos, npos;
int dfn[10005], low[10005], g[10005], s[10005], vis[10005];
int last[10005], pre[100005], to[100005];
set<int> scc[10005];
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    s[++spos] = now;
    for (int i = last[now]; i != 0; i = pre[i])
    {
        int t = to[i];
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
    if (low[now] == dfn[now])
    {
        ++gpos;
        while (now != s[spos])
        {
            scc[gpos].insert(s[spos]);
            g[s[spos--]] = gpos;
        }
        scc[gpos].insert(s[spos]);
        g[s[spos--]] = gpos;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[i] = v, pre[i] = last[u];
        last[u] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    cout << gpos << endl;
    for (int i = 1; i <= n; i++)
    {
        int gi = g[i];
        if (scc[gi].size() == 0 || vis[gi])
        {
            continue;
        }
        vis[gi] = 1;
        for (set<int>::iterator it = scc[gi].begin(); it != scc[gi].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}