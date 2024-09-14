#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n, m, k, dgr[2005][2005], rec[2005][2005];
int ms[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct Path
{
    int x, y, t;
    bool operator<(const Path &oth) const
    {
        return t > oth.t;
    }
};
priority_queue<Path> q;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            dgr[i][j] = (c == 'X'), rec[i][j] = 1e9;
        }
    }
    q.push(Path{1, 1, 0});
    while (q.size())
    {
        int x = q.top().x, y = q.top().y, t = q.top().t;
        q.pop();
        if (rec[x][y] != 1e9)
        {
            continue;
        }
        rec[x][y] = t;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx < 1 || ny < 1 || nx > n || ny > m || rec[nx][ny] != 1e9 || dgr[nx][ny])
            {
                continue;
            }
            q.push(Path{nx, ny, t + (i > 1)});
        }
    }
    int tb = rec[n][m], ta = n + m - 2 + rec[n][m];
    long long ans = 1e18, t = 0;
    for (int i = 1; i <= k; i++)
    {
        long long a, b;
        cin >> a >> b;
        long long res = a * ta + b * tb;
        if (res < ans)
        {
            ans = res, t = 1;
        }
        else if (res == ans)
        {
            t++;
        }
    }
    cout << ans << " " << t << endl;
    return 0;
}
// TAG: 最短路 BFS 记忆化