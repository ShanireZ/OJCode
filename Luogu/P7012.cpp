#include <algorithm>
#include <iostream>
using namespace std;
int a[15][15], T, ans;
int ms[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void dfs(int x, int y, int cnt)
{
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx >= 1 && ny >= 1 && nx <= 10 && ny <= 10 && a[nx][ny] == 1)
        {
            int tx = nx + ms[i][0], ty = ny + ms[i][1];
            if (tx >= 1 && ty >= 1 && tx <= 10 && ty <= 10 && a[tx][ty] == 0)
            {
                a[tx][ty] = 2, a[x][y] = 0, a[nx][ny] = 0;
                dfs(tx, ty, cnt + 1);
                a[tx][ty] = 0, a[x][y] = 2, a[nx][ny] = 1;
            }
        }
    }
}
int main()
{
    cin >> T;
    while (T--)
    {
        ans = 0;
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '.')
                {
                    a[i][j] = -1;
                }
                else if (ch == 'B')
                {
                    a[i][j] = 1;
                }
                else if (ch == 'W')
                {
                    a[i][j] = 2;
                }
                else
                {
                    a[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                if (a[i][j] == 2)
                {
                    dfs(i, j, 0);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}