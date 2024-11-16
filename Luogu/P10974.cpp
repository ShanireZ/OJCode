#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int to;
    long long w;
};
vector<Edge> es[200005];
long long dp[200005], ans;
void dfs(int now, int from)
{
    for (Edge e : es[now])
    {
        if (e.to == from)
        {
            continue;
        }
        dfs(e.to, now);
        dp[now] += ((dp[e.to] == 0) ? e.w : min(dp[e.to], e.w));
    }
}
void dfs2(int now, int from, long long d)
{
    dp[now] += (dp[from] == d ? d : min(dp[from] - min(dp[now], d), d));
    ans = max(ans, dp[now]);
    for (Edge e : es[now])
    {
        if (e.to == from)
        {
            continue;
        }
        dfs2(e.to, now, e.w);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            es[i].clear(), dp[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            es[u].emplace_back(Edge{v, w}), es[v].emplace_back(Edge{u, w});
        }
        ans = 0;
        dfs(1, 0);
        dfs2(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}