#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, step;
};
queue<Node> q;
int n, sx, sy, fx, fy, mp[105][105], vis[105][105];
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
            if (ch == 'A')
            {
                mp[i][j] = 100, sx = i, sy = j;
            }
            else if (ch == 'B')
            {
                mp[i][j] = 200, fx = i, fy = j;
            }
            else if (ch == '+')
            {
                mp[i][j] = 1;
            }
        }
    }
    q.push(Node{sx, sy, 0}), vis[sx][sy] = 1;
    while (q.size())
    {
        int x = q.front().x, y = q.front().y, step = q.front().step;
        q.pop();
        if (x == fx && y == fy)
        {
            cout << step << "\n";
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny] || mp[nx][ny] == mp[x][y])
            {
                continue;
            }
            q.push(Node{nx, ny, step + 1}), vis[nx][ny] = 1;
        }
    }
    return 0;
}