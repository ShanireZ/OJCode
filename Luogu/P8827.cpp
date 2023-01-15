#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Edge
{
    int x, y;
};
Edge es[MX];
int v[MX], tot[MX], fa[MX];
vector<int> g[MX];
void dfs(int now)
{
    for (int i = 0; i < g[now].size(); i++)
    {
        int nxt = g[now][i];
        if (nxt != fa[now])
        {
            fa[nxt] = now;
            dfs(nxt);
            tot[now] += tot[nxt];
        }
    }
}
void edit(int now, int add)
{
    tot[now] += add;
    while (fa[now])
    {
        now = fa[now];
        tot[now] += add;
    }
}
void cut(int wid)
{
    int a = es[wid].x, b = es[wid].y;
    if (fa[a] == b)
    {
        swap(a, b);
    }
    fa[b] = 0, tot[a] -= tot[b];
    while (fa[a])
    {
        a = fa[a];
        tot[a] -= tot[b];
    }
}
void query(int now)
{
    while (fa[now])
    {
        now = fa[now];
    }
    cout << tot[now] << "\n";
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        tot[i] = v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
        es[i].x = a, es[i].y = b;
    }
    dfs(1);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            cut(x);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            edit(x, y - v[x]);
            v[x] = y;
        }
        else if (op == 3)
        {
            cin >> x;
            query(x);
        }
    }
    return 0;
}