#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w;
};
vector<Edge> es[1005];
int n, m, dis[1005], cnt[1005], inq[1005];
queue<int> q;
bool spfa(int st) // 求最大减少量==最长路
{
    fill(dis, dis + n + 1, -0x3f3f3f3f);
    dis[st] = 0, inq[st] = 1, q.push(st);
    while (q.size())
    {
        int now = q.front();
        inq[st] = 0, q.pop();
        for (Edge e : es[now])
        {
            int nxt = e.v, w = e.w;
            if (dis[nxt] < dis[now] + w)
            {
                dis[nxt] = dis[now] + w;
                if (inq[nxt] == 0)
                {
                    q.push(nxt), cnt[nxt]++;
                    if (cnt[nxt] >= n)
                    {
                        return false; // 有正环
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{u, v, w}); // 注意w为减少量
    }
    if (spfa(1) == false)
    {
        cout << "Forever love" << endl;
        return 0;
    }
    int ans = dis[n];
    if (spfa(n) == false)
    {
        cout << "Forever love" << endl;
        return 0;
    }
    cout << -max(ans, dis[1]) << endl;
    return 0;
}