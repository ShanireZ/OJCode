#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    int pos, cost;
    bool operator<(const Path &oth) const
    {
        return cost > oth.cost;
    }
};
priority_queue<Path> pq;
vector<int> to[100005];
int n, m, a, b, v[100005], dis[100005];
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[a] = 0, pq.push(Path{a, 0});
    while (pq.size())
    {
        int now = pq.top().pos, w = pq.top().cost;
        pq.pop();
        if (w > dis[now])
        {
            continue;
        }
        for (int nxt : to[now])
        {
            if (dis[now] + 1 < dis[nxt])
            {
                dis[nxt] = dis[now] + 1;
                pq.push(Path{nxt, dis[nxt]});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> a >> b;
    a++, b++;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        to[x + 1].push_back(y + 1);
    }
    dijkstra();
    if (dis[b] == 0x3f3f3f3f)
    {
        cout << "No solution" << endl;
        return 0;
    }
    cout << v[b] - v[a] + dis[b] << endl;
    return 0;
}