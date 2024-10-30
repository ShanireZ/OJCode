#include <algorithm>
#include <iostream>
using namespace std;
int mp[1005][1005], vis[1005][1005], n, m, k, T;
int ms[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    cin >> T;
    while (T--)
    {
        int x, y, d, res = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                mp[i][j] = (c == '.' ? 1 : 0), vis[i][j] = 0;
            }
        }
        vis[x][y] = 1, res++;
        while (k--)
        {
            int nx = x + ms[d][0], ny = y + ms[d][1];
            if (nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] == 0)
            {
                d = (d + 1) % 4;
                continue;
            }
            x = nx, y = ny;
            if (vis[x][y] == 0)
            {
                vis[x][y] = 1, res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}