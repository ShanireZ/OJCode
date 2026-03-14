#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int to, c;
};
vector<Edge> es[100005];
struct Path
{
    int p, d;
    bool operator<(Path oth) const
    {
        return d > oth.d;
    }
};
priority_queue<Path> pq;
int n, m, dis[50005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        es[a].push_back(Edge{b, c});
        es[b].push_back(Edge{a, c});
    }
    fill(dis + 1, dis + 1 + n, 1e9);
    pq.push(Path{1, 0});
    while (pq.size())
    {
        int now = pq.top().p, tot = pq.top().d;
        pq.pop();
        if (tot < dis[now])
        {
            dis[now] = tot;
            for (Edge e : es[now])
            {
                int nxt = e.to, c = e.c;
                if (dis[now] + c < dis[nxt])
                {
                    pq.push(Path{nxt, dis[now] + c});
                }
            }
        }
    }
    cout << dis[n] << endl;
    return 0;
}