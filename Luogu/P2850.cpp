#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[505];
int t, n, m, w, trig, dis[505], inq[505], cnt[505];
queue<int> q;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> w;
        fill(dis, dis + n + 2, 0x3f3f3f3f);
        fill(inq, inq + n + 2, 0), fill(cnt, cnt + n + 2, 0);
        while (q.size())
        {
            q.pop();
        }
        es[n + 1].clear(); // 超级源点
        for (int i = 1; i <= n; i++)
        {
            es[i].clear();
            es[n + 1].push_back(Edge{i, 0});
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            es[u].push_back(Edge{v, w});
            es[v].push_back(Edge{u, w});
        }
        for (int i = 1; i <= w; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            es[u].push_back(Edge{v, -w});
        }
        q.push(n + 1), inq[n + 1] = 1, dis[n + 1] = 0, trig = 0;
        while (q.size())
        {
            int now = q.front();
            q.pop(), inq[now] = 0;
            for (Edge e : es[now])
            {
                int nxt = e.v, w = e.w;
                if (dis[nxt] > dis[now] + w)
                {
                    dis[nxt] = dis[now] + w;
                    if (inq[nxt] == 0)
                    {
                        q.push(nxt), inq[nxt] = 1, cnt[nxt]++;
                        if (cnt[nxt] >= n)
                        {
                            trig = 1;
                            goto opt;
                        }
                    }
                }
            }
        }
    opt:
        cout << (trig ? "YES" : "NO") << endl;
    }
    return 0;
}