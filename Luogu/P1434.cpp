#include <iostream>
using namespace std;
int r, c, ans, h[105][105], dp[105][105], vis[105][105];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    int way = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx < 1 || ny < 1 || nx > r || ny > c || vis[nx][ny] || h[nx][ny] >= h[x][y])
        {
            continue;
        }
        if (dp[nx][ny] == 1)
        {
            dfs(nx, ny);
        }
        way = max(way, dp[nx][ny] + 1);
    }
    dp[x][y] = way;
    vis[x][y] = 0;
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> h[i][j];
            dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (dp[i][j] == 1)
            {
                dfs(i, j);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}