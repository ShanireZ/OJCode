#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, step;
};
Node ns[2005];
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
Edge es[4000005];
queue<Node> q;
int n, m, pos, ans, mp[200][200], dis[200][200], g[2005];
int ms[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}};
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
        mp[ns[i].x][ns[i].y] = g[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        memset(dis, 0x3f, sizeof(dis));
        dis[ns[i].x][ns[i].y] = 0, q.push(Node{ns[i].x, ns[i].y, 0});
        while (q.size())
        {
            Node now = q.front();
            q.pop();
            if (mp[now.x][now.y])
            {
                es[++pos] = Edge{i, mp[now.x][now.y], now.step};
            }
            for (int j = 0; j < 8; j++)
            {
                int nx = now.x + ms[j][0], ny = now.y + ms[j][1];
                if (nx > m || ny > m || nx < 1 || ny < 1 || dis[nx][ny] <= now.step + 1)
                {
                    continue;
                }
                dis[nx][ny] = now.step + 1;
                q.push(Node{nx, ny, now.step + 1});
            }
        }
    }
    sort(es + 1, es + pos + 1);
    for (int i = 1; i <= pos; i++)
    {
        int ga = dfn(es[i].u), gb = dfn(es[i].v);
        if (ga != gb)
        {
            g[ga] = gb, ans += es[i].w + 1;
        }
    }
    cout << ans << endl;
    return 0;
}