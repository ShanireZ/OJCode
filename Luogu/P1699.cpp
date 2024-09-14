#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, d;
};
queue<Node> q;
int sx, sy, fx, fy, a[15][15], rec[15][15];
int ms[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            char c;
            cin >> c;
            if (c == 'L')
            {
                sx = i, sy = j;
            }
            else if (c == 'B')
            {
                fx = i, fy = j;
            }
            a[i][j] = (c == 'R'), rec[i][j] = 1e9;
        }
    }
    q.push(Node{sx, sy, 0});
    while (q.size())
    {
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop();
        if (d < rec[x][y])
        {
            rec[x][y] = d;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + ms[i][0], ny = y + ms[i][1];
                if (nx < 1 || ny < 1 || nx > 10 || ny > 10 || a[nx][ny])
                {
                    continue;
                }
                if (d + 1 < rec[nx][ny])
                {
                    q.push(Node{nx, ny, d + 1});
                }
            }
        }
    }
    cout << rec[fx][fy] - 1 << endl;
    return 0;
}