#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
int a[1005][1005], t[1005][1005], ms[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
queue<Node> q;
int main()
{
    memset(t, 0x3f, sizeof(t));
    int n, sx, sy, fx, fy;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    cin >> sx >> sy >> fx >> fy;
    q.push(Node{sx, sy}), t[sx][sy] = 0;
    while (q.size())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        if (x == fx && y == fy)
        {
            cout << t[x][y] << endl;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny] == 1)
            {
                continue;
            }
            if (t[nx][ny] > t[x][y] + 1)
            {
                t[nx][ny] = t[x][y] + 1, q.push(Node{nx, ny});
            }
        }
    }
    return 0;
}