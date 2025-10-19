#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[200005];
int n, k, rpos, cpos, root, ans, dis[1000005];
int vis[200005], rec[200005][2], cl[200005], sz[200005], zson[200005];
void zx(int now, int from, int sum)
{
    sz[now] = 1, zson[now] = 0;
    for (Edge e : es[now])
    {
        if (vis[e.v] || e.v == from)
        {
            continue;
        }
        zx(e.v, now, sum);
        sz[now] += sz[e.v], zson[now] = max(zson[now], sz[e.v]);
    }
    zson[now] = max(zson[now], sum - sz[now]);
    if (zson[now] <= sum / 2)
    {
        root = now;
    }
}
void dfs(int now, int from, int d, int step)
{
    rec[++rpos][0] = d, rec[rpos][1] = step;
    for (Edge e : es[now])
    {
        if (vis[e.v] || e.v == from || d + e.w > k)
        {
            continue;
        }
        dfs(e.v, now, d + e.w, step + 1);
    }
}
void f(int now)
{
    vis[now] = 1, cpos = 0, dis[0] = 0;
    for (Edge e : es[now])
    {
        if (vis[e.v] || e.w > k)
        {
            continue;
        }
        rpos = 0, dfs(e.v, now, e.w, 1);
        for (int i = 1; i <= rpos; i++)
        {
            if (dis[k - rec[i][0]] != 0x3f3f3f3f)
            {
                ans = min(ans, dis[k - rec[i][0]] + rec[i][1]);
            }
        }
        for (int i = 1; i <= rpos; i++)
        {
            dis[rec[i][0]] = min(dis[rec[i][0]], rec[i][1]);
            cl[++cpos] = rec[i][0];
        }
    }
    for (int i = 1; i <= cpos; i++)
    {
        dis[cl[i]] = 0x3f3f3f3f;
    }
    for (Edge e : es[now])
    {
        if (vis[e.v])
        {
            continue;
        }
        root = e.v, zx(e.v, now, sz[e.v]);
        f(root);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    root = 1, zx(1, 0, n);
    memset(dis, 0x3f, sizeof(dis));
    ans = 1e7, f(root);
    cout << (ans == 1e7 ? -1 : ans) << endl;
    return 0;
}