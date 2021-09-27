#include <iostream>
#include <queue>
#include <string>
using namespace std;
int xz[100005], mp[1505][1505], n, m, ans, cnt;
int ms[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
struct Star
{
    int x, y;
    Star(int X, int Y)
    {
        x = X, y = Y;
    }
};
queue<Star> q;
void bfs(int sx, int sy)
{
    q.push(Star(sx, sy));
    mp[sx][sy] = 0;
    int tot = 1;
    while (q.size())
    {
        Star now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int tx = now.x + ms[i][0], ty = now.y + ms[i][1];
            if (tx < 0 || tx == n || ty < 0 || ty == m || mp[tx][ty] == 0)
            {
                continue;
            }
            q.push(Star(tx, ty));
            mp[tx][ty] = 0;
            tot++;
        }
    }
    xz[tot]++;
    if (xz[tot] == 1)
    {
        cnt++;
    }
    ans = max(ans, tot * xz[tot]);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string info;
        cin >> info;
        for (int j = 0; j < m; j++)
        {
            if (info[j] == '*')
            {
                mp[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}