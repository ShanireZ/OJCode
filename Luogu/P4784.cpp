#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    long long v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[100005];
priority_queue<Edge> pq;
int n, m, k, mc[10];
long long dp[100005][100];
void dijkstra(int sta)
{
    while (pq.size())
    {
        long long now = pq.top().v, dis = pq.top().w;
        pq.pop();
        if (dis == dp[now][sta])
        {
            for (Edge e : es[now])
            {
                int nxt = e.v;
                if (dp[nxt][sta] > dp[now][sta] + e.w)
                {
                    dp[nxt][sta] = dp[now][sta] + e.w;
                    pq.push(Edge{nxt, dp[nxt][sta]});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> k >> m;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= k; i++)
    {
        cin >> mc[i];
        dp[mc[i]][1 << (i - 1)] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    for (int sta = 1; sta < (1 << k); sta++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int pre = sta & (sta - 1); pre; pre = sta & (pre - 1))
            {
                dp[i][sta] = min(dp[i][sta], dp[i][pre] + dp[i][sta ^ pre]);
            }
            if (dp[i][sta] != 0x3f3f3f3f3f3f3f3f)
            {
                pq.push(Edge{i, dp[i][sta]});
            }
        }
        dijkstra(sta);
    }
    cout << dp[mc[1]][(1 << k) - 1] << endl;
    return 0;
}