#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[10005];
int dis[10000005], backup[10000005], vis[10005], rec[10005], sz[10005], zson[10005];
int ans[105], q[105], n, m, rpos, bpos, root;
void zx(int now, int from, int sum)
{
    sz[now] = 1, zson[now] = 0;
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (nxt == from || vis[nxt])
        {
            continue;
        }
        zx(nxt, now, sum);
        sz[now] += sz[nxt], zson[now] = max(zson[now], sz[nxt]);
    }
    zson[now] = max(zson[now], sum - sz[now]);
    if (zson[now] <= sum / 2)
    {
        root = now;
    }
}
void dfs(int now, int from, int d)
{
    rec[++rpos] = d;
    for (Edge e : es[now])
    {
        int nxt = e.v, w = e.w;
        if (nxt == from || vis[nxt] || d + w > 1e7)
        {
            continue;
        }
        dfs(nxt, now, d + w);
    }
}
void f(int now)
{
    vis[now] = 1, bpos = 0;
    for (Edge e : es[now])
    {
        int nxt = e.v, w = e.w;
        if (vis[nxt])
        {
            continue;
        }
        rpos = 0, dfs(nxt, now, w);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= rpos && ans[i] == 0; j++)
            {
                if (q[i] - rec[j] >= 0 && dis[q[i] - rec[j]])
                {
                    ans[i] = 1;
                }
            }
        }
        for (int i = 1; i <= rpos; i++)
        {
            dis[rec[i]] = 1, backup[++bpos] = rec[i];
        }
    }
    for (int i = 1; i <= bpos; i++)
    {
        dis[backup[i]] = 0;
    }
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (vis[nxt])
        {
            continue;
        }
        zx(nxt, now, sz[nxt]);
        f(root);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i];
    }
    dis[0] = 1, zx(1, 0, n);
    f(root);
    for (int i = 1; i <= m; i++)
    {
        cout << (ans[i] ? "AYE" : "NAY") << "\n";
    }
    return 0;
}