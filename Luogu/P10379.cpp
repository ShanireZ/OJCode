#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, bool> mp;
int n, m, ans, a[505][505], vis[505][505];
int fw[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string s;
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + fw[i][0], ny = y + fw[i][1];
        if (vis[nx][ny] == 0 && a[x][y] == a[nx][ny] && nx <= n && ny <= m && nx >= 1 && ny >= 1)
        {
            vis[nx][ny] = 1;
            s += ('0' + i);
            dfs(nx, ny);
        }
    }
    s += 'b'; // 如果只看方向，很容易出现类似连续操作和不连续操作，数字都一样的情况
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0)
            {
                s.clear();
                dfs(i, j);
                if (mp[s] == 0)
                {
                    ans++, mp[s] = 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}