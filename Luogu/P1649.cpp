#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, f, t;
};
queue<Node> q;
int n, sx, sy, fx, fy, a[105][105], mn[105][105];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'x')
            {
                a[i][j] = -1;
            }
            else if (ch == 'A')
            {
                sx = i, sy = j;
            }
            else if (ch == 'B')
            {
                fx = i, fy = j;
            }
            mn[i][j] = 1e9;
        }
    }
    mn[sx][sy] = 0;
    q.push(Node{sx, sy, 0, 0}), q.push(Node{sx, sy, 1, 0});
    q.push(Node{sx, sy, 2, 0}), q.push(Node{sx, sy, 3, 0});
    while (q.size())
    {
        int x = q.front().x, y = q.front().y, f = q.front().f, t = q.front().t;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx < 1 || ny < 1 || nx > n || ny > n || a[nx][ny] == -1)
            {
                continue;
            }
            if (f == i && mn[nx][ny] >= t)
            {
                mn[nx][ny] = t;
                q.push({nx, ny, i, t});
            }
            else if (f != i && mn[nx][ny] >= t + 1) // 必须留相同次数，因为有可能次数一样但到达时的方向不一样
            {
                mn[nx][ny] = t + 1;
                q.push({nx, ny, i, t + 1});
            }
        }
    }
    cout << (mn[fx][fy] == 1e9 ? -1 : mn[fx][fy]) << endl;
    return 0;
}