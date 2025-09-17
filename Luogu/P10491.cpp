#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, v;
};
queue<Node> q;
int n, m, fx, fy, a[155][155];
int ms[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                a[i][j] = -1;
            }
            else if (ch == 'H')
            {
                fx = i, fy = j;
            }
            else if (ch == 'K')
            {
                q.push(Node{i, j, 0}), a[i][j] = -1;
            }
        }
    }
    while (q.size())
    {
        int x = q.front().x, y = q.front().y, v = q.front().v;
        q.pop();
        if (x == fx && y == fy)
        {
            cout << v << endl;
            return 0;
        }
        for (int i = 0; i < 8; i++)
        {
            int tx = x + ms[i][0], ty = y + ms[i][1];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == 0)
            {
                q.push(Node{tx, ty, v + 1}), a[tx][ty] = -1;
            }
        }
    }
    return 0;
}