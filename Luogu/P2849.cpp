#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 存边和计算最短路时，都可用k来进行限制优化
struct Edge
{
    int v, w;
};
vector<Edge> to[505];
int n, k, pos[505][2], dis[505][505], done[505][505];
struct Path
{
    int v, w, t;
    bool operator<(const Path oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> q;
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    q.push(Path{1, 0, 0}), dis[1][0] = 0;
    while (q.size())
    {
        int now = q.top().v, t = q.top().t;
        q.pop();
        if (done[now][t])
        {
            continue;
        }
        done[now][t] = 1;
        for (int i = 0; i < int(to[now].size()); i++)
        {
            int nxt = to[now][i].v, w = to[now][i].w;
            if (dis[now][t] + w < dis[nxt][t + (nxt - now - 1)])
            {
                dis[nxt][t + (nxt - now - 1)] = dis[now][t] + w;
                q.push(Path{nxt, dis[now][t] + w, t + (nxt - now - 1)});
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
        for (int j = 1; j <= i - 1; j++)
        {
            to[j].push_back(Edge{i, abs(pos[j][0] - pos[i][0]) + abs(pos[j][1] - pos[i][1])});
        }
    }
    dijkstra();
    cout << dis[n][k] << endl;
    return 0;
}