#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int to, w;
    bool operator<(Edge oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Edge> q;
vector<Edge> es[50005];
int n, m, dis[50005];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        es[a].push_back(Edge{b, 1});
    }
    fill(dis + 1, dis + 1 + n, 1e9);
    q.push(Edge{1, 0});
    while (q.size())
    {
        int now = q.top().to, w = q.top().w;
        q.pop();
        if (w < dis[now])
        {
            dis[now] = w;
            for (Edge e : es[now])
            {
                if (e.w + dis[now] < dis[e.to])
                {
                    q.push(Edge{e.to, e.w + dis[now]});
                }
            }
        }
    }
    if (dis[n] == 1e9)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dis[n] + 1 << endl;
    return 0;
}