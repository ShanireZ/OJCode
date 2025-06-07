#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 500005
struct Edge
{
    int to, id;
};
vector<Edge> es[MX];
vector<int> g[MX], rec;
int n, m, gpos, npos, dfn[MX], low[MX];
void tarjan(int now, int from)
{
    dfn[now] = low[now] = ++npos;
    rec.push_back(now);
    for (Edge e : es[now])
    {
        if (e.id == from)
        {
            continue;
        }
        int nxt = e.to;
        if (dfn[nxt] == 0)
        {
            tarjan(nxt, e.id);
            low[now] = min(low[now], low[nxt]);
        }
        else
        {
            low[now] = min(low[now], dfn[nxt]);
        }
    }
    if (dfn[now] == low[now])
    {
        gpos++;
        for (int i = rec.size() - 1; i >= 0; i--)
        {
            int x = rec[i];
            g[gpos].push_back(x), rec.pop_back();
            if (now == x)
            {
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
        es[u].push_back(Edge{v, i}), es[v].push_back(Edge{u, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i, 0);
        }
    }
    cout << gpos << endl;
    for (int i = 1; i <= gpos; i++)
    {
        cout << g[i].size() << " ";
        for (int j : g[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}