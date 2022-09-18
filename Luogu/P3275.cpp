#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 100005
queue<int> q;
long long dis[MX];
int n, m, epos, npos, gpos, spos;
int last[MX], pre[MX * 4], to[MX * 4], d[MX * 4], dfn[MX], low[MX], g[MX], cnt[MX], s[MX], nlast[MX], ind[MX];
void addEdge(int u, int v, int w, int eid, int opt)
{
    to[eid] = v, d[eid] = w;
    if (opt == 1)
    {
        pre[eid] = last[u];
        last[u] = eid;
    }
    else
    {
        pre[eid] = nlast[u];
        nlast[u] = eid;
    }
}
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    s[++spos] = now;
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
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
        ++gpos;
        while (s[spos] != now)
        {
            g[s[spos--]] = gpos, cnt[gpos]++;
        }
        g[s[spos--]] = gpos, cnt[gpos]++;
    }
}
bool makeScc(int now)
{
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i], w = d[i];
        if (g[now] != g[nxt])
        {
            addEdge(g[now], g[nxt], w, ++epos, 2);
            ind[g[nxt]]++;
        }
        else if (w == 1)
        {
            return false;
        }
    }
    return true;
}
void TP()
{
    for (int i = 1; i <= gpos; i++)
    {
        dis[i] = 1;
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = nlast[now]; i; i = pre[i])
        {
            int nxt = to[i], w = d[i];
            if (--ind[nxt] == 0)
            {
                q.push(nxt);
            }
            dis[nxt] = max(dis[nxt], dis[now] + w);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int opt, a, b;
        cin >> opt >> a >> b;
        if (a == b && opt % 2 == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        if (opt == 1)
        {
            addEdge(a, b, 0, ++epos, 1);
            addEdge(b, a, 0, ++epos, 1);
        }
        else if (opt == 2)
        {
            addEdge(a, b, 1, ++epos, 1);
        }
        else if (opt == 3)
        {
            addEdge(b, a, 0, ++epos, 1);
        }
        else if (opt == 4)
        {
            addEdge(b, a, 1, ++epos, 1);
        }
        else
        {
            addEdge(a, b, 0, ++epos, 1);
        }
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
        if (makeScc(i) == false)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    TP();
    long long tot = 0;
    for (int i = 1; i <= gpos; i++)
    {
        tot += cnt[i] * dis[i];
    }
    cout << tot << endl;
    return 0;
}