#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    long long v, w;
};
vector<Edge> g[15];
long long vis[15], n, m, ans = 0x3f3f3f3f3f3f3f3f;
void dfs(int now, long long sum)
{
    if (now == n)
    {
        ans = min(ans, sum);
        return;
    }
    for (Edge e : g[now])
    {
        long long nxt = e.v, w = e.w;
        if (vis[nxt])
        {
            continue;
        }
        vis[nxt] = 1, dfs(nxt, sum ^ w);
        vis[nxt] = 0;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vis[1] = 1, dfs(1, 0);
    cout << ans << endl;
    return 0;
}