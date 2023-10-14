#include <algorithm>
#include <iostream>
using namespace std;
int n, m, res, h[105][105], ans[105][105];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y, int step)
{
    ans[x][y] = step, res = max(res, step);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && h[nx][ny] > h[x][y])
        {
            if (ans[nx][ny] < step + 1)
            {
                dfs(nx, ny, step + 1);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ans[i][j] == 0)
            {
                dfs(i, j, 1);
            }
        }
    }
    cout << res << endl;
    return 0;
}