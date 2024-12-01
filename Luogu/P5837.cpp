#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, c, f;
};
vector<Edge> es[1005];
queue<int> q;
pair<int, int> dis[1005]; // 流量 花费
int n, m, vis[1005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        es[a].push_back({b, c, f}), es[b].push_back({a, c, f});
    }
    q.push(1), vis[1] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (Edge e : es[now])
        {
            int nxt = e.v;
            int f = (dis[now].first == 0 ? e.f : min(dis[now].first, e.f));
            int c = dis[now].second + e.c;
            if (dis[nxt] == make_pair(0, 0) || 1.0 * dis[nxt].first / dis[nxt].second < 1.0 * f / c)
            {
                dis[nxt] = {f, c};
                if (vis[nxt] == 0)
                {
                    q.push(nxt), vis[nxt] = 1;
                }
            }
        }
    }
    cout << (long long)(1000000.0 * dis[n].first / dis[n].second) << endl;
    return 0;
}