#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Path
{
    int x, y, d;
    bool operator<(const Path oth) const
    {
        return d > oth.d;
    }
};
priority_queue<Path> q;
int a[2005][2005], rec[2005][2005], t, n, m;
int ms[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string res;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                a[i][j] = c - '0', rec[i][j] = 1e9;
            }
        }
        q.push(Path{1, 1, 0});
        while (q.size())
        {
            int x = q.top().x, y = q.top().y, d = q.top().d;
            q.pop();
            if (rec[x][y] != 1e9)
            {
                continue;
            }
            rec[x][y] = d;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + ms[i][0], ny = y + ms[i][1];
                if (nx < 1 || ny < 1 || nx > n || ny > m || rec[nx][ny] != 1e9 || a[x][y] == a[nx][ny])
                {
                    continue;
                }
                q.push(Path{nx, ny, d + 1});
            }
        }
        if (rec[n][m] == 1e9)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << rec[n][m] << endl;
            res.clear();
            int x = n, y = m;
            while (x != 1 || y != 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + ms[i][0], ny = y + ms[i][1];
                    if (nx < 1 || ny < 1 || nx > n || ny > m || rec[nx][ny] + 1 != rec[x][y] || a[x][y] == a[nx][ny])
                    {
                        continue;
                    }
                    res += (i == 0 ? 'U' : (i == 1 ? 'L' : (i == 2 ? 'D' : 'R')));
                    x = nx, y = ny;
                    break;
                }
            }
            for (int i = res.size() - 1; i >= 0; i--)
            {
                cout << res[i];
            }
            cout << endl;
        }
    }
    return 0;
}
// TAG: 最短路 BFS 记忆化