#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[225];
queue<int> q;
int dis[225], cnt[225], vis[225], n, m1, m2, s, ec;
int main()
{
    cin >> ec >> m1 >> n >> m2 >> s;
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(Edge{v, ec});
    }
    for (int i = 1; i <= m2; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, ec - w});
    }
    memset(dis, -0x3f, sizeof(dis));
    dis[s] = ec, q.emplace(s);
    while (q.size())
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (Edge e : es[now])
        {
            int nxt = e.v, w = e.w;
            if (dis[nxt] < dis[now] + w)
            {
                dis[nxt] = dis[now] + w;
                if (vis[nxt] == 0)
                {
                    vis[nxt] = 1, q.emplace(nxt);
                    if (++cnt[nxt] > n)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dis[i]);
    }
    cout << ans << endl;
    return 0;
}