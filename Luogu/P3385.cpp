#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> to[2005];
queue<int> q;
int n, m, T, ok, dis[2005], inq[2005], l[2005];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            to[i].clear(), dis[i] = 0x3f3f3f3f;
            l[i] = 0, inq[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (w >= 0)
            {
                to[v].emplace_back(Edge{u, w});
            }
            to[u].emplace_back(Edge{v, w});
        }
        while (q.size())
        {
            q.pop();
        }
        ok = 1, dis[1] = 0, inq[1] = 1, q.emplace(1);
        while (q.size() && ok)
        {
            int now = q.front();
            inq[now] = 0, q.pop();
            for (Edge e : to[now])
            {
                if (dis[e.v] > dis[now] + e.w)
                {
                    dis[e.v] = dis[now] + e.w, l[e.v] = l[now] + 1;
                    if (l[e.v] == n)
                    {
                        ok = 0;
                        break;
                    }
                    if (inq[e.v] == 0)
                    {
                        inq[e.v] = 1, q.emplace(e.v);
                    }
                }
            }
        }
        cout << (ok ? "NO" : "YES") << endl;
    }
    return 0;
}