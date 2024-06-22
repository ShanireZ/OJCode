#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
mt19937 rnd(time(0));
int n, ans1, ans2, pos;
int mp[255][255], vis[255][255], ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs1(int x, int y, int n1, int &tot)
{
    vis[x][y] = pos, tot++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx < 1 || ny < 1 || nx > n || ny > n || vis[nx][ny] == pos || mp[nx][ny] != n1)
        {
            continue;
        }
        dfs1(nx, ny, n1, tot);
    }
}
void dfs2(int x, int y, int n1, int n2, int &tot)
{
    vis[x][y] = pos, tot++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx < 1 || ny < 1 || nx > n || ny > n || vis[nx][ny] == pos || (mp[nx][ny] != n1 && mp[nx][ny] != n2))
        {
            continue;
        }
        dfs2(nx, ny, n1, n2, tot);
    }
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j] == 0)
            {
                int res = 0;
                ++pos, dfs1(i, j, mp[i][j], res);
                ans1 = max(ans1, res);
            }
        }
    }
    cout << ans1 << endl;
    for (int i = 1; i <= 966; i++)
    {
        int x, y, f = 5;
        while (f == 5)
        {
            x = rnd() % (n - 2) + 2, y = rnd() % (n - 2) + 2; // 2~n-1
            for (int j = 0; j < 4; j++)
            {
                int nx = x + ms[j][0], ny = y + ms[j][1];
                if (mp[nx][ny] != mp[x][y])
                {
                    f = j;
                    break;
                }
            }
        }
        int res = 0;
        ++pos, dfs2(x, y, mp[x][y], mp[x + ms[f][0]][y + ms[f][1]], res);
        ans2 = max(ans2, res);
    }
    cout << ans2 << endl;
    return 0;
}
// TAG: 搜索 随机算法