#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[200005];
int n, res[200005], zs[200005];
void dfs(int now, int fa)
{
    for (Edge e : es[now])
    {
        if (e.v == fa)
        {
            continue;
        }
        zs[now] += e.w; // 统计该点下方逆边数量
        dfs(e.v, now);
        zs[now] += zs[e.v];
    }
}
void dfs2(int now, int fa)
{
    for (Edge e : es[now])
    {
        if (e.v == fa)
        {
            continue;
        }
        res[e.v] = res[now] + (e.w == 1 ? -1 : 1);
        dfs2(e.v, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        es[a].push_back(Edge{b, 0});
        es[b].push_back(Edge{a, 1});
    }
    dfs(1, 0);
    res[1] = zs[1];
    dfs2(1, 0);
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, res[i]);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (ans == res[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}