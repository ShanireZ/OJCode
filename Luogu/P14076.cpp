#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    long long to, w;
};
vector<Edge> es[100005];
long long ans, n, mx, dis[100005];
void dfs(int now, int from)
{
    if (es[now].size() == 1)
    {
        mx = max(mx, dis[now]);
    }
    for (Edge e : es[now])
    {
        if (e.to == from)
        {
            continue;
        }
        dis[e.to] = dis[now] + e.w;
        dfs(e.to, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
        ans += w;
    }
    dfs(1, 0);
    cout << ans * 2 - mx << endl;
    return 0;
}