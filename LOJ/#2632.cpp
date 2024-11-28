#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, opt, v;
    bool operator<(const Node &oth) const
    {
        return v > oth.v;
    }
};
priority_queue<Node> q;
int n, m, mp[505][505], dis[505][505][2], vis[505][505][2];
int ms1[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ms2[4][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = (ch == '/' ? 0 : 1);
        }
    }
    int ex = (mp[1][1] == 0) + (mp[n][m] == 0);
    mp[1][1] = mp[n][m] = 1;
    memset(dis, 0x3f, sizeof(dis));
    q.push(Node{1, 1, 1, ex}), dis[1][1][1] = ex;
    while (q.size())
    {
        int x = q.top().x, y = q.top().y, opt = q.top().opt;
        q.pop();
        if (vis[x][y][opt])
        {
            continue;
        }
        vis[x][y][opt] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms1[i][0], ny = y + ms1[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
            {
                continue;
            }
            if (mp[nx][ny] == opt && dis[nx][ny][!opt] > dis[x][y][opt] + 1)
            {
                q.push(Node{nx, ny, !opt, dis[x][y][opt] + 1});
                dis[nx][ny][!opt] = min(dis[nx][ny][!opt], dis[x][y][opt] + 1);
            }
            else if (mp[nx][ny] != opt && dis[nx][ny][!opt] > dis[x][y][opt])
            {
                q.push(Node{nx, ny, !opt, dis[x][y][opt]});
                dis[nx][ny][!opt] = min(dis[nx][ny][!opt], dis[x][y][opt]);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms2[i][0], ny = y + ms2[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m || (opt == 1 && i >= 2) || (opt == 0 && i < 2))
            {
                continue;
            }
            if (mp[nx][ny] == opt && dis[nx][ny][opt] > dis[x][y][opt])
            {
                q.push(Node{nx, ny, opt, dis[x][y][opt]});
                dis[nx][ny][opt] = min(dis[nx][ny][opt], dis[x][y][opt]);
            }
            else if (mp[nx][ny] != opt && dis[nx][ny][opt] > dis[x][y][opt] + 1)
            {
                q.push(Node{nx, ny, opt, dis[x][y][opt] + 1});
                dis[nx][ny][opt] = min(dis[nx][ny][opt], dis[x][y][opt] + 1);
            }
        }
    }
    if (dis[n][m][1] == 0x3f3f3f3f)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        cout << dis[n][m][1] << endl;
    }
    return 0;
}