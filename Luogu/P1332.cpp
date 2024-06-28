#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
queue<Node> q;
int n, m, a, b, t[505][505], ms[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int main()
{
    memset(t, 0x3f, sizeof(t));
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        int x, y;
        cin >> x >> y;
        t[x][y] = 0, q.push(Node{x, y});
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
            if (t[nx][ny] > t[x][y] + 1)
            {
                t[nx][ny] = t[x][y] + 1, q.push(Node{nx, ny});
            }
        }
    }
    for (int i = 1; i <= b; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << t[x][y] << '\n';
    }
    return 0;
}