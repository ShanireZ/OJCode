#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    int v;
    long long w;
    bool operator<(const Path &oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> pq;
int n, m, k, s, sta[100005], vis[100005];
long long p, q, cost[100005];
queue<pair<int, int>> danger;
vector<int> to[100005];
int main()
{
    cin >> n >> m >> k >> s >> p >> q;
    for (int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        sta[c] = 1, danger.push({c, 0}); // 禁止进入
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    while (danger.size())
    {
        int now = danger.front().first, step = danger.front().second;
        danger.pop();
        for (int nxt : to[now])
        {
            if (sta[nxt])
            {
                continue;
            }
            sta[nxt] = 2; // 危险区域
            if (step + 1 < s)
            {
                danger.push({nxt, step + 1});
            }
        }
    }
    fill(cost, cost + 1 + n, 1e15);
    cost[1] = 0, pq.push(Path{1, 0});
    while (pq.size())
    {
        int now = pq.top().v;
        pq.pop();
        if (vis[now])
        {
            continue;
        }
        vis[now] = 1;
        for (int nxt : to[now])
        {
            if (sta[nxt] == 1 || cost[nxt] <= cost[now] + (sta[nxt] == 0 ? p : q))
            {
                continue;
            }
            cost[nxt] = cost[now] + (sta[nxt] == 0 ? p : q);
            pq.push(Path{nxt, cost[nxt]});
        }
    }
    cout << cost[n] - (sta[n] == 0 ? p : q) << endl;
    return 0;
}