#include <algorithm>
#include <iostream>
using namespace std;
int vis[105][105], x[10005], y[10005], pos;
int ms[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            vis[i][j] = (c == '#');
        }
    }
    x[0] = y[0] = 1, vis[1][1] = 1;
    for (int i = 0; i <= pos; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nx = x[i] + ms[j][0], ny = y[i] + ms[j][1];
            if (nx == n && ny == m)
            {
                cout << "Yes";
                return 0;
            }
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0)
            {
                vis[nx][ny] = 1;
                x[++pos] = nx, y[pos] = ny;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}