#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, step;
    bool operator<(const Node &oth) const
    {
        return step > oth.step;
    }
};
priority_queue<Node> q;
int mp[1005][1005], dis[1005][1005], n, m, sx, sy, fx, fy;
int ms[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = (ch == '#');
        }
    }
    cin >> sx >> sy >> fx >> fy;
    memset(dis, 0x3f, sizeof(dis));
    q.emplace(Node{sx, sy, 0}), dis[sx][sy] = 0;
    while (q.size())
    {
        int x = q.top().x, y = q.top().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
            {
                continue;
            }
            if (mp[nx][ny] == 0 && dis[nx][ny] > dis[x][y])
            {
                dis[nx][ny] = dis[x][y], q.emplace(Node{nx, ny, dis[x][y]});
            }
            else if (mp[nx][ny] && dis[nx][ny] > dis[x][y] + 1)
            {
                dis[nx][ny] = dis[x][y] + 1, q.emplace(Node{nx, ny, dis[x][y] + 1});
            }
            int nnx = nx + ms[i][0], nny = ny + ms[i][1];
            if (nnx < 1 || nnx > n || nny < 1 || nny > m)
            {
                continue;
            }
            if (dis[nnx][nny] > dis[x][y] + 1)
            {
                dis[nnx][nny] = dis[x][y] + 1, q.emplace(Node{nnx, nny, dis[x][y] + 1});
            }
        }
    }
    cout << dis[fx][fy] << endl;
    return 0;
}