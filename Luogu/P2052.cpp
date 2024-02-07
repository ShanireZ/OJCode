#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    long long v, w;
};
vector<Edge> to[1000005];
long long n, ans, sz[1000005], w[1000005];
void dfs(int now, int fa)
{
    sz[now] = 1;
    for (Edge e : to[now])
    {
        long long nxt = e.v;
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now);
        sz[now] += sz[nxt], w[nxt] = e.w;
    }
    ans += w[now] * abs(n - sz[now] - sz[now]);
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        to[u].push_back(Edge{v, w}), to[v].push_back(Edge{u, w});
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
// TAG: 树上DP 搜索