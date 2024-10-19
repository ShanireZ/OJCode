#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    int v, w;
    bool operator<(const Path &oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> q;
int n, m, s, t, d, oes[105][105], es[105][105], dis[105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        oes[u][v] = oes[v][u] = w;
    }
    cin >> d;
    for (int i = 1; i <= d; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u][v] = es[v][u] = oes[u][v];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (oes[i][j] == 0)
            {
                es[i][j] = 0x3f3f3f3f;
            }
        }
    }
    cin >> s >> t;
    fill(dis, dis + 105, 0x3f3f3f3f);
    q.emplace(Path{s, 0});
    while (q.size())
    {
        int now = q.top().v, w = q.top().w;
        q.pop();
        if (dis[now] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[now] = w;
        for (int nxt = 1; nxt <= n; nxt++)
        {
            if (dis[nxt] > dis[now] + es[now][nxt])
            {
                q.emplace(Path{nxt, dis[now] + es[now][nxt]});
            }
        }
    }
    cout << dis[t] << endl;
    return 0;
}