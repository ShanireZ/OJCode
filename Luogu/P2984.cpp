#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[50005];
int n, m, b, dis[50005];
queue<int> q;
int main()
{
    cin >> n >> m >> b;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w}), es[v].push_back(Edge{u, w});
    }
    fill(dis + 1, dis + n + 1, 0x3f3f3f3f);
    dis[1] = 0, q.push(1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (Edge e : es[now])
        {
            int nxt = e.v, w = e.w;
            if (dis[now] + w < dis[nxt])
            {
                dis[nxt] = dis[now] + w, q.push(nxt);
            }
        }
    }
    while (b--)
    {
        int u, v;
        cin >> u >> v;
        cout << dis[u] + dis[v] << '\n';
    }
    return 0;
}