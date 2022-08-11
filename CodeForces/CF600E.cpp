#include <iostream>
using namespace std;
#define MX 100005
int last[MX], pre[MX * 2], to[MX * 2], fa[MX], zson[MX], sz[MX];
long long col[MX], cnt[MX], ans[MX], maxc;
int n, epos, root = 1, maxt;
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
void dfs1(int now)
{
    sz[now] = 1;
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        if (t == fa[now])
        {
            continue;
        }
        fa[t] = now;
        dfs1(t);
        sz[now] += sz[t];
        if (sz[t] > sz[zson[now]])
        {
            zson[now] = t;
        }
    }
}
void count(int now, int add, int saved = 0)
{
    cnt[col[now]] += add;
    if (cnt[col[now]] > maxt)
    {
        maxc = col[now], maxt = cnt[col[now]];
    }
    else if (cnt[col[now]] == maxt)
    {
        maxc += col[now];
    }
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        if (t == fa[now] || t == saved)
        {
            continue;
        }
        count(t, add, saved);
    }
}
void dfs2(int now, bool keep)
{
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        if (t == fa[now] || t == zson[now])
        {
            continue;
        }
        dfs2(t, false);
    }
    if (zson[now])
    {
        dfs2(zson[now], true);
    }
    count(now, 1, zson[now]);
    ans[now] = maxc;
    if (keep == 0)
    {
        count(now, -1);
        maxc = maxt = 0;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y, ++epos);
        addEdge(y, x, ++epos);
    }
    dfs1(root);
    dfs2(root, true);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}