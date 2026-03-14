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
int n, m, pb, pa1, pa2, dis1[100005], dis2[100005];
int main()
{
    cin >> m >> n >> pb >> pa1 >> pa2;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        es[a].push_back(Edge{b, c});
        es[b].push_back(Edge{a, c});
    }
    fill(dis1 + 1, dis1 + 1 + n, 2e9);
    fill(dis2 + 1, dis2 + 1 + n, 2e9);
    pq.push(Path{pa1, 0});
    while (pq.size())
    {
        int now = pq.top().p, tot = pq.top().d;
        pq.pop();
        if (tot < dis1[now])
        {
            dis1[now] = tot;
            for (Edge e : es[now])
            {
                int nxt = e.to, c = e.c;
                if (dis1[now] + c < dis1[nxt])
                {
                    pq.push(Path{nxt, dis1[now] + c});
                }
            }
        }
    }
    pq.push(Path{pa2, 0});
    while (pq.size())
    {
        int now = pq.top().p, tot = pq.top().d;
        pq.pop();
        if (tot < dis2[now])
        {
            dis2[now] = tot;
            for (Edge e : es[now])
            {
                int nxt = e.to, c = e.c;
                if (dis2[now] + c < dis2[nxt])
                {
                    pq.push(Path{nxt, dis2[now] + c});
                }
            }
        }
    }
    cout << min(dis1[pb] + dis1[pa2], dis2[pb] + dis2[pa1]) << endl;
    return 0;
}