#include <algorithm>
#include <iostream>
using namespace std;
int n, m, nid, gid, spos;
int to[40005], pre[40005], last[20005];
int g[20005], dfn[20005], low[20005], s[20005];
void addEdge(int u, int v, int eid)
{
    to[eid] = v, pre[eid] = last[u];
    last[u] = eid;
}
void tarjan(int now)
{
    dfn[now] = low[now] = ++nid, s[++spos] = now;
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++) // 2i-1 -> i  2i -> i+n
    {
        int a, b;
        cin >> a >> b;
        addEdge(a / 2 + a % 2 + n * (a % 2 ^ 1), b / 2 + b % 2 + n * (b % 2), i * 2 - 1);
        addEdge(b / 2 + b % 2 + n * (b % 2 ^ 1), a / 2 + a % 2 + n * (a % 2), i * 2);
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == g[i + n])
        {
            cout << "NIE" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i * 2 - (g[i] < g[i + n]) << endl;
    }
    return 0;
}