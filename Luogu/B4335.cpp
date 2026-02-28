#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, pos, a[15][15], f[100][3], vis[15][15];
void dfs(int now, int sum)
{
    if (now > pos)
    {
        return;
    }
    int ok = 1;
    for (int i = f[now][0]; i <= f[now][0] + 2; i++)
    {
        for (int j = f[now][1]; j <= f[now][1] + 2; j++)
        {
            if (vis[i][j] == 1)
            {
                ok = 0;
                break;
            }
        }
    }
    dfs(now + 1, sum);
    if (ok)
    {
        for (int i = f[now][0]; i <= f[now][0] + 2; i++)
        {
            for (int j = f[now][1]; j <= f[now][1] + 2; j++)
            {
                vis[i][j] = 1;
            }
        }
        sum += f[now][2], ans = max(ans, sum);
        dfs(now + 1, sum);
        sum -= f[now][2];
        for (int i = f[now][0]; i <= f[now][0] + 2; i++)
        {
            for (int j = f[now][1]; j <= f[now][1] + 2; j++)
            {
                vis[i][j] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = 1; j <= n - 2; j++)
        {
            int sum = 0;
            for (int x = i; x <= i + 2; x++)
            {
                for (int y = j; y <= j + 2; y++)
                {
                    sum += a[x][y];
                }
            }
            if (sum > 0)
            {
                pos++;
                f[pos][0] = i, f[pos][1] = j, f[pos][2] = sum;
            }
        }
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}