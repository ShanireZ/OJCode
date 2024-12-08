#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, vis;
};
Edge es[100005];
vector<int> to[100005];
int g[100005], way[100005];
int dfn(int x)
{
    return (x == g[x] ? x : g[x] = dfn(g[x]));
}
int dfs(int now, int from, int step, int tar)
{
    if (now == tar)
    {
        return step;
    }
    for (int eid : to[now])
    {
        int nxt = es[eid].u + es[eid].v - now;
        if (nxt == from)
        {
            continue;
        }
        way[step] = eid;
        int res = dfs(nxt, now, step + 1, tar);
        if (res)
        {
            return res;
        }
    }
    return 0;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, ok = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            g[i] = i, to[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> es[i].u >> es[i].v;
            es[i].vis = 0;
            int gu = dfn(es[i].u), gv = dfn(es[i].v);
            if (gu != gv)
            {
                g[gu] = gv, es[i].vis = 1;
                to[es[i].u].push_back(i), to[es[i].v].push_back(i);
            }
        }
        for (int i = 1; i <= m && ok == 0; i++)
        {
            if (es[i].vis == 1)
            {
                continue;
            }
            int step = dfs(es[i].u, 0, 1, es[i].v);
            way[step] = i, ok = 1;
            sort(way + 1, way + step + 1);
            for (int j = 1; j <= step; j++)
            {
                cout << way[j] << " ";
            }
        }
        if (ok == 0)
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}