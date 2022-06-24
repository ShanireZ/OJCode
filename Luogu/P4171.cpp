#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int k, n, m, spos, gid, nid;
int pre[2005], to[2005];
int dfn[205], low[205], last[205], g[205], s[205];
void init()
{
    gid = spos = nid = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(g, 0, sizeof(g));
    memset(last, 0, sizeof(last));
}
void addEdge(int u, int v, int eid)
{
    to[eid] = v, pre[eid] = last[u];
    last[u] = eid;
}
void tarjan(int now)
{
    dfn[now] = low[now] = ++nid;
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
        gid++;
        while (s[spos] != now)
        {
            g[s[spos--]] = gid;
        }
        g[s[spos--]] = gid;
    }
}
int main()
{
    cin >> k;
    while (k--)
    {
        init();
        cin >> n >> m;
        for (int i = 1; i <= m; i++) // m -> 1~n h -> n+1~2n
        {
            char a, b;
            int x, y;
            cin >> a >> x >> b >> y;
            addEdge(x + (a == 'm') * n, y + (b == 'h') * n, i * 2 - 1);
            addEdge(y + (b == 'm') * n, x + (a == 'h') * n, i * 2);
        }
        for (int i = 1; i <= n * 2; i++)
        {
            if (dfn[i] == 0)
            {
                tarjan(i);
            }
        }
        int ok = 1;
        for (int i = 1; i <= n; i++)
        {
            if (g[i] == g[i + n])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << "GOOD" << endl;
        }
        else
        {
            cout << "BAD" << endl;
        }
    }
    return 0;
}