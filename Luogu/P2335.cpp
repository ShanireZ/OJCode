#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
queue<Node> q;
int dis[155][155], ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int c;
            cin >> c;
            if (c != 1)
            {
                dis[i][j] = 0x3f3f3f3f;
            }
            else
            {
                q.push(Node{i, j});
            }
        }
    }
    while (q.size())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
            {
                continue;
            }
            if (dis[nx][ny] > dis[x][y] + 1)
            {
                dis[nx][ny] = dis[x][y] + 1;
                q.push(Node{nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// TAG: 搜索 最短路 P1256