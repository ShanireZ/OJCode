#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[105];
int n, m, k, s[15], dis[105], dp[105][2100];
priority_queue<Edge> pq;
void dijkstra(int sta)
{
    while (pq.size())
    {
        int now = pq.top().v, w = pq.top().w;
        pq.pop();
        if (dp[now][sta] == w)
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
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= k; i++)
    {
        cin >> s[i];
        dp[s[i]][1 << (i - 1)] = 0;
    }
    for (int sta = 2; sta < (1 << k); sta++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int pre = sta & (sta - 1); pre; pre = sta & (pre - 1)) // 列举sta的所有非空子集
            {
                dp[i][sta] = min(dp[i][sta], dp[i][pre] + dp[i][sta ^ pre]);
            }
            if (dp[i][sta] != 0x3f3f3f3f)
            {
                pq.push(Edge{i, dp[i][sta]});
            }
        }
        dijkstra(sta);
    }
    cout << dp[s[1]][(1 << k) - 1] << endl;
    return 0;
}