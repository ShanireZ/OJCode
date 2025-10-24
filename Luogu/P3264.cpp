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
vector<Edge> es[1005];
vector<int> chan[15];
priority_queue<Edge> pq;
int n, m, p, ans[1100], sch[15], dp[1005][1100];
void dijkstra(int sta)
{
    while (pq.size())
    {
        int now = pq.top().v, dis = pq.top().w;
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
void dfs(int now, int sta)
{
    if (now > p)
    {
        for (int i = 1; i <= n; i++)
        {
            ans[sta] = min(ans[sta], dp[i][sta]);
        }
        return;
    }
    dfs(now + 1, sta);
    dfs(now + 1, sta | sch[now]);
}
int main()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    for (int i = 1; i <= p; i++)
    {
        int c, d;
        cin >> c >> d;
        chan[c].push_back(d);
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1, pos = 0; i <= p; i++)
    {
        for (int d : chan[i])
        {
            dp[d][1 << pos] = 0, sch[i] |= (1 << pos);
            pos++;
        }
    }
    for (int sta = 1; sta < (1 << p); sta++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int pre = sta & (sta - 1); pre; pre = sta & (pre - 1))
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
    memset(ans, 0x3f, sizeof(ans));
    dfs(1, 0);                               // 每个合法状态的最小花费
    for (int sta = 1; sta < (1 << p); sta++) // 合法状态相互组合
    {
        for (int pre = sta & (sta - 1); pre; pre = sta & (pre - 1))
        {
            ans[sta] = min(ans[sta], ans[pre] + ans[sta ^ pre]);
        }
    }
    cout << ans[(1 << p) - 1] << endl;
    return 0;
}