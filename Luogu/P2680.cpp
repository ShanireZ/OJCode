#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 300005
struct Edge
{
    int to, t;
};
vector<Edge> es[MX];
int n, m, t, mx, ok, pth[MX][4], anc[MX][20], d[MX][20], h[MX], cnt[MX];
void dfs(int now, int from)
{
    for (int i = 1; i <= 19; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
        d[now][i] = d[now][i - 1] + d[anc[now][i - 1]][i - 1];
    }
    for (Edge e : es[now])
    {
        if (e.to == from)
        {
            continue;
        }
        anc[e.to][0] = now, d[e.to][0] = e.t, h[e.to] = h[now] + 1;
        dfs(e.to, now);
    }
}
pair<int, int> lca(int a, int b)
{
    int res = 0;
    if (h[a] < h[b])
    {
        swap(a, b);
    }
    for (int i = 19; i >= 0; i--)
    {
        if (h[anc[a][i]] >= h[b])
        {
            res += d[a][i];
            a = anc[a][i];
        }
    }
    if (a == b)
    {
        return {a, res};
    }
    for (int i = 19; i >= 0; i--)
    {
        if (anc[a][i] != anc[b][i])
        {
            res += d[a][i] + d[b][i];
            a = anc[a][i], b = anc[b][i];
        }
    }
    return {anc[a][0], res + d[a][0] + d[b][0]};
}
void dfs2(int now, int from)
{
    for (Edge e : es[now])
    {
        if (e.to == from)
        {
            continue;
        }
        dfs2(e.to, now);
        cnt[now] += cnt[e.to];
    }
    if (cnt[now] == t && mx <= d[now][0])
    {
        ok = 1;
    }
}
bool check(int lmt)
{
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 0;
    }
    t = 0, mx = 0, ok = 0;
    for (int i = 1; i <= m; i++)
    {
        if (pth[i][3] > lmt)
        {
            cnt[pth[i][0]]++, cnt[pth[i][1]]++, cnt[pth[i][2]] -= 2;
            t++, mx = max(mx, pth[i][3] - lmt);
        }
    }
    dfs2(1, 0);
    return ok;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w}), es[v].push_back(Edge{u, w});
    }
    h[1] = 1, dfs(1, 0);
    int r = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> pth[i][0] >> pth[i][1];
        pair<int, int> res = lca(pth[i][0], pth[i][1]);
        pth[i][2] = res.first, pth[i][3] = res.second;
        r = max(r, res.second);
    }
    int l = max(0, r - 1000);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        check(mid) ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
// TAG: LCA 二分答案 倍增