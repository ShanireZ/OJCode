#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[20005];
int n, rpos, root, a, b, t[5], rec[20005], vis[20005], sz[20005], zson[20005];
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
        int nxt = e.v;
        if (nxt == from || vis[nxt])
        {
            continue;
        }
        dfs(nxt, now, (d + e.w) % 3);
    }
}
void f(int now)
{
    vis[now] = 1;
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (vis[nxt])
        {
            continue;
        }
        rpos = 0, dfs(nxt, now, e.w % 3);
        for (int i = 1; i <= rpos; i++)
        {
            a += t[(3 - rec[i]) % 3] * 2;
        }
        for (int i = 1; i <= rpos; i++)
        {
            t[rec[i]]++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        t[i] = 0;
    }
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (vis[nxt])
        {
            continue;
        }
        root = nxt, zx(nxt, now, sz[nxt]);
        t[0] = 1, f(root);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    root = 1, zx(1, 0, n);
    t[0] = 1, f(root);
    b = n * n, a += n;
    int g = __gcd(a, b);
    cout << a / g << "/" << b / g << "\n";
    return 0;
}