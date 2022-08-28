#include <iostream>
using namespace std;
int f, r, npos, gpos, spos, cnt;
int pre[20005], to[20005], last[5005], dfn[5005], low[5005], s[5005], g[5005], d[5005];
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
void tarjan(int now, int from)
{
    low[now] = dfn[now] = ++npos, s[++spos] = now;
    for (int i = last[now]; i; i = pre[i])
    {
        if ((i ^ from) == 1)
        {
            continue;
        }
        int t = to[i];
        if (dfn[t] == 0)
        {
            tarjan(t, i);
            low[now] = min(low[now], low[t]);
        }
        else
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
    if (low[now] == dfn[now])
    {
        gpos++;
        while (s[spos] != now)
        {
            g[s[spos--]] = gpos;
        }
        g[s[spos--]] = gpos;
    }
}
int main()
{
    cin >> f >> r;
    for (int i = 1; i <= r; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b, i * 2), addEdge(b, a, i * 2 + 1);
    }
    tarjan(1, 0);
    for (int i = 1; i <= f; i++)
    {
        for (int j = last[i]; j; j = pre[j])
        {
            int t = to[j];
            if (g[i] != g[t])
            {
                d[g[i]]++, d[g[t]]++;
            }
        }
    }
    for (int i = 1; i <= gpos; i++)
    {
        if (d[i] == 2)
        {
            cnt++;
        }
    }
    cout << (cnt + 1) / 2 << endl;
    return 0;
}