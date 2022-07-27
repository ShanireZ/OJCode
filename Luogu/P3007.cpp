#include <algorithm>
#include <iostream>
using namespace std;
int m, n, spos, gpos, npos, epos;
int g[2005], dfn[2005], low[2005], s[2005], ans[2005];
int pre[16005], to[16005], last[2005], glast[2005];
char opt[5] = {0, 'Y', 'N', '?'};
void addEdge(int u, int v)
{
    ++epos;
    to[epos] = v, pre[epos] = last[u];
    last[u] = epos;
}
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos, s[++spos] = now;
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
    if (dfn[now] == low[now])
    {
        ++gpos;
        while (s[spos] != now)
        {
            g[s[spos--]] = gpos;
        }
        g[s[spos--]] = gpos;
    }
}
void scc()
{
    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = last[i]; j != 0; j = pre[j])
        {
            int t = to[j];
            if (g[i] != g[t])
            {
                ++epos;
                to[epos] = g[t], pre[epos] = glast[g[i]];
                glast[g[i]] = epos;
            }
        }
    }
}
bool dfs(int now, int target)
{
    if (now == target)
    {
        return 0;
    }
    for (int i = glast[now]; i != 0; i = pre[i])
    {
        int t = to[i];
        if (dfs(t, target) == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) // 1~n:Y n+1~2n:N
    {
        int a, b, ca, cb;
        char x, y;
        cin >> a >> x >> b >> y;
        ca = (x == 'Y') ? 1 : 0;
        cb = (y == 'Y') ? 1 : 0;
        addEdge(a + n * ca, b + n * (!cb));
        addEdge(b + n * cb, a + n * (!ca));
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    scc();
    for (int i = 1; i <= n; i++)
    {
        ans[i] = dfs(g[i], g[i + n]) + dfs(g[i + n], g[i]) * 2;
        if (ans[i] == 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << opt[ans[i]];
    }
    cout << endl;
    return 0;
}