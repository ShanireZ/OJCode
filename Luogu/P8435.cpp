#include <iostream>
#include <vector>
using namespace std;
int n, m, spos, gpos, npos;
int pre[4000005], to[4000005], last[500005], s[500005], dfn[500005], low[500005];
vector<int> g[500005];
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
void tarjan(int now, int from)
{
    dfn[now] = low[now] = ++npos, s[++spos] = now;
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
            if (low[t] >= dfn[now])
            {
                g[++gpos].push_back(now);
                while (s[spos] != t)
                {
                    g[gpos].push_back(s[spos--]);
                }
                g[gpos].push_back(s[spos--]);
            }
        }
        else
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b) // 自环 #1 #11 wa
        {
            continue;
        }
        addEdge(a, b, i * 2), addEdge(b, a, i * 2 + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i, 0);
            if (last[i] == 0)
            {
                g[++gpos].push_back(i);
            }
        }
    }
    cout << gpos << endl;
    for (int i = 1; i <= gpos; i++)
    {
        cout << g[i].size() << " ";
        for (int j = 0; j < int(g[i].size()); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}