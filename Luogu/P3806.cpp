#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int to, w;
};
vector<Edge> es[10005];
int n, m, root, pos, rpos, qst[105], ans[105], chk[10000005];
int sz[10005], maxct[10005], rem[10005], rec[10005], vis[10005];
void findroot(int now, int fa, int tot, int &res)
{
    sz[now] = 1, maxct[now] = 0;
    for (Edge e : es[now])
    {
        int nxt = e.to;
        if (nxt == fa || vis[nxt])
        {
            continue;
        }
        findroot(nxt, now, tot, res), sz[now] += sz[nxt];
        maxct[now] = max(maxct[now], sz[nxt]);
    }
    maxct[now] = max(maxct[now], tot - sz[now]);
    if (maxct[now] < maxct[res])
    {
        res = now;
    }
}
void dfs(int now, int fa, int dis)
{
    if (dis <= 10000000)
    {
        rem[++pos] = dis;
    }
    for (Edge e : es[now])
    {
        int nxt = e.to, w = e.w;
        if (nxt == fa || vis[nxt])
        {
            continue;
        }
        dfs(nxt, now, w + dis);
    }
}
void solve(int now)
{
    vis[now] = 1, rpos = 0;
    for (Edge e : es[now]) // 经过root
    {
        int nxt = e.to, w = e.w;
        if (vis[nxt])
        {
            continue;
        }
        pos = 0, dfs(nxt, now, w);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= pos && ans[i] == 0; j++)
            {
                int delt = qst[i] - rem[j];
                if (delt >= 0 && chk[delt])
                {
                    ans[i] = 1;
                    break;
                }
            }
        }
        for (int i = 1; i <= pos; i++)
        {
            if (chk[rem[i]] == 0)
            {
                chk[rem[i]] = 1, rec[++rpos] = rem[i];
            }
        }
    }
    for (int i = 1; i <= rpos; i++)
    {
        chk[rec[i]] = 0;
    }
    for (Edge e : es[now]) // 不经过root
    {
        int nxt = e.to;
        if (vis[nxt])
        {
            continue;
        }
        int croot = 0;
        findroot(nxt, now, sz[nxt], croot);
        solve(croot);
    }
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        es[u].push_back(Edge{v, w}), es[v].push_back(Edge{u, w});
    }
    for (int i = 1; i <= m; i++)
    {
        qst[i] = read();
    }
    maxct[0] = n, findroot(1, 0, n, root);
    chk[0] = 1, solve(root);
    for (int i = 1; i <= m; i++)
    {
        printf("%s\n", (ans[i] ? "AYE" : "NAY"));
    }
    return 0;
}
// TAG: 树的重心 点分治 树分治