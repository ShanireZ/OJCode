#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int mp[505][505], dp[505][505], vis[505][505];
int ms[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pair<int, int>> q;
int main()
{
    int n, m, x1, y1, x2, y2;
    cin >> n >> m;
    while (n)
    {
        memset(dp, 0x3f, sizeof(dp)), memset(vis, 0, sizeof(vis));
        int trig = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char ch;
                cin >> ch;
                mp[i][j] = (ch == '#' ? 0 : 1);
            }
        }
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;
        q.push({x1, y1}), vis[x1][y1] = 1, dp[x1][y1] = 0;
        while (q.size())
        {
            int x = q.front().first, y = q.front().second;
            q.pop(), vis[x][y] = 0;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + ms[i][0], ny = y + ms[i][1];
                if (nx < 1 || ny < 1 || nx > n || ny > m || dp[nx][ny] <= dp[x][y] + (mp[nx][ny] != mp[x][y]))
                {
                    continue;
                }
                dp[nx][ny] = dp[x][y] + (mp[nx][ny] != mp[x][y]);
                if (vis[nx][ny] == 0)
                {
                    q.push({nx, ny}), vis[nx][ny] = 1;
                }
            }
        }
        cout << dp[x2][y2] << endl;
        cin >> n >> m;
    }
}