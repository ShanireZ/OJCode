#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<int> s;
int a[55][55], g[55][55], c[2505], n, gpos, cnt, ans;
int ms[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y)
{
    g[x][y] = gpos, cnt++;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + ms[k][0], ny = y + ms[k][1];
        if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny] == 0 || g[nx][ny])
        {
            continue;
        }
        dfs(nx, ny);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = (ch == 'A');
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] && g[i][j] == 0)
            {
                gpos++, cnt = 0;
                dfs(i, j);
                c[gpos] = cnt;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                cnt = 1, s.clear();
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + ms[k][0], nj = j + ms[k][1];
                    s.insert(g[ni][nj]);
                }
                for (int k : s)
                {
                    cnt += c[k];
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}