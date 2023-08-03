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
vector<int> to[MX];
void dfs(int now)
{
    for (int nxt : to[now])
    {
        if (nxt != fa[now])
        {
            fa[nxt] = now, dfs(nxt);
            tot[now] += tot[nxt];
        }
    }
}
void cut(int wid)
{
    int a = es[wid].x, b = es[wid].y;
    if (fa[a] == b)
    {
        swap(a, b);
    }
    fa[b] = 0;
    while (a)
    {
        tot[a] -= tot[b];
        a = fa[a];
    }
}
void edit(int now, int add)
{
    v[now] += add;
    while (now)
    {
        tot[now] += add;
        now = fa[now];
    }
}
int query(int now)
{
    while (fa[now])
    {
        now = fa[now];
    }
    return tot[now];
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
        to[a].push_back(b), to[b].push_back(a);
        es[i].x = a, es[i].y = b;
    }
    dfs(1);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        cin >> opt >> x;
        if (opt == 1)
        {
            cut(x);
        }
        else if (opt == 2)
        {
            cin >> y;
            edit(x, y - v[x]);
        }
        else if (opt == 3)
        {
            cout << query(x) << "\n";
        }
    }
    return 0;
}