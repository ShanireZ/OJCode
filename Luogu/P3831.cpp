#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    int to, d;
    bool operator<(const Path np) const
    {
        return d > np.d;
    }
    Path(int To, int D)
    {
        to = To, d = D;
    }
};
priority_queue<Path> p;
struct Edge
{
    int t, w;
    Edge(int T, int W)
    {
        t = T, w = W;
    }
};
vector<Edge> es[300005];
struct Node
{
    int x, y, id;
};
Node ns[100005];
bool cmpx(Node a, Node b)
{
    return (a.x == b.x) ? a.y < b.y : a.x < b.x;
}
bool cmpy(Node a, Node b)
{
    return (a.y == b.y) ? a.x < b.x : a.y < b.y;
}
int sx, sy, fx, fy, n, m, cnt, dis[300005];
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    p.push(Path(m + 1, 0));
    while (p.size())
    {
        int now = p.top().to, d = p.top().d;
        p.pop();
        if (dis[now] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[now] = d;
        for (int i = 0; i < es[now].size(); i++)
        {
            int to = es[now][i].t, nd = es[now][i].w;
            if (dis[to] > d + nd)
            {
                p.push(Path(to, d + nd));
            }
        }
    }
}
void makeg()
{
    for (int i = 1; i <= cnt; i++)
    {
        es[i].push_back(Edge(i + cnt, 1));
        es[i + cnt].push_back(Edge(i, 1));
        if (i > m)
        {
            es[i].push_back(Edge(i + cnt, 0));
            es[i + cnt].push_back(Edge(i, 0));
        }
    }
    sort(ns + 1, ns + 1 + cnt, cmpx);
    for (int i = 1; i < cnt; i++)
    {
        if (ns[i].x == ns[i + 1].x)
        {
            es[ns[i].id].push_back(Edge(ns[i + 1].id, 2 * (ns[i + 1].y - ns[i].y)));
            es[ns[i + 1].id].push_back(Edge(ns[i].id, 2 * (ns[i + 1].y - ns[i].y)));
        }
    }
    sort(ns + 1, ns + 1 + cnt, cmpy);
    for (int i = 1; i < cnt; i++)
    {
        if (ns[i].y == ns[i + 1].y)
        {
            es[ns[i].id + cnt].push_back(Edge(ns[i + 1].id + cnt, 2 * (ns[i + 1].x - ns[i].x)));
            es[ns[i + 1].id + cnt].push_back(Edge(ns[i].id + cnt, 2 * (ns[i + 1].x - ns[i].x)));
        }
    }
}
int main()
{
    cin >> n >> m;
    cnt = m + 2;
    for (int i = 1; i <= cnt; i++)
    {
        cin >> ns[i].x >> ns[i].y;
        ns[i].id = i;
    }
    makeg();
    dijkstra();
    if (dis[cnt] == 0x3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[cnt] << endl;
    }
    return 0;
}