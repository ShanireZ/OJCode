#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int rec[105][105], n, m, sx, sy, ex, ey;
int ms[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int>> q;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            rec[i][j] = 1e9;
            char c;
            cin >> c;
            if (c == '*')
            {
                rec[i][j] = -1;
            }
            else if (c == 'C')
            {
                sx == 0 ? sx = i, sy = j : ex = i, ey = j;
            }
        }
    }
    q.emplace(make_pair(sx, sy)), rec[sx][sy] = -1;
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            while (rec[nx][ny] >= rec[x][y] + 1 && nx <= n && ny <= m && nx >= 1 && ny >= 1)
            {
                q.emplace(make_pair(nx, ny)), rec[nx][ny] = rec[x][y] + 1;
                nx += ms[i][0], ny += ms[i][1];
            }
        }
    }
    cout << rec[ex][ey] << endl;
    return 0;
}