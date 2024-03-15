#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 10005
struct Edge
{
    int v, w;
};
vector<Edge> es[MX];
int n, m, rpos, cpos, qst[105], ans[105], len[10000005];
int sz[MX], zson[MX], vis[MX], rec[MX], clist[MX];
void findroot(int now, int fa, int sum, int &res)
{
    sz[now] = 1, zson[now] = 0;
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (nxt == fa || vis[nxt])
        {
            continue;
        }
        findroot(nxt, now, sum, res);
        sz[now] += sz[nxt];
        zson[now] = max(zson[now], sz[nxt]);
    }
    zson[now] = max(zson[now], sum - sz[now]);
    if (zson[now] < zson[res])
    {
        res = now;
    }
}
void dfs(int now, int fa, int dis)
{
    if (dis <= 10000000)
    {
        rec[++rpos] = dis;
    }
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (nxt == fa || vis[nxt])
        {
            continue;
        }
        dfs(nxt, now, dis + e.w);
    }
}
void solve(int now)
{
    vis[now] = 1, cpos = 0;
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (vis[nxt])
        {
            continue;
        }
        rpos = 0, dfs(nxt, now, e.w);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= rpos && ans[i] == 0; j++)
            {
                int delta = qst[i] - rec[j];
                if (delta >= 0 && len[delta])
                {
                    ans[i] = 1;
                    break;
                }
            }
        }
        for (int i = 1; i <= rpos; i++)
        {
            int x = rec[i];
            if (len[x] == 0)
            {
                len[x] = 1, clist[++cpos] = x;
            }
        }
    }
    for (int i = 1; i <= cpos; i++)
    {
        len[clist[i]] = 0;
    }
    for (Edge e : es[now])
    {
        int nxt = e.v;
        if (vis[nxt])
        {
            continue;
        }
        int root = 0;
        findroot(nxt, now, sz[nxt], root);
        solve(root);
    }
}
int main()
{
    ios::sync_with_stdio(false);
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
        cin >> qst[i];
    }
    int root = 0;
    zson[0] = n, len[0] = 1;
    findroot(1, 0, n, root);
    solve(root);
    for (int i = 1; i <= m; i++)
    {
        cout << (ans[i] ? "AYE" : "NAY") << "\n";
    }
    return 0;
}