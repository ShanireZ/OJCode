#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int a[105][105], dp[105][105], n, m, s, ans;
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<pair<int, int>> q;
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s = s * 345 % 19997;
            dp[i][j] = a[i][j] = s % 10 + 1;
            q.emplace(make_pair(i, j));
        }
    }
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop(), ans = max(ans, dp[x][y]);
        for (int k = 0; k < 4; k++)
        {
            int nx = x + ms[k][0], ny = y + ms[k][1];
            if (a[nx][ny] > a[x][y] && dp[x][y] + a[nx][ny] > dp[nx][ny])
            {
                dp[nx][ny] = dp[x][y] + a[nx][ny];
                q.emplace(make_pair(nx, ny));
            }
        }
    }
    cout << ans << endl;
    return 0;
}