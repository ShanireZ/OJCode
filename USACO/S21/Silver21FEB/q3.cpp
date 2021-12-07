#include <iostream>
#include <cstring>
using namespace std;
int all[505][505][2], lx[505][505], n;
// cnt横向统计连续个数 all原矩阵 [0]大于100 [1]大于等于100
long long cnt(int op)
{
    memset(lx, 0, sizeof(lx));
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (all[i][j][op] == 1)
            {
                lx[i][j] = lx[i][j + 1] + 1;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int now = lx[i][j], x = i;
            while (now)
            {
                ans += now, x++;
                now = min(lx[x][j], now);
            }
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x >= 100)
            {
                if (x > 100)
                {
                    all[i][j][0] = 1;
                }
                all[i][j][1] = 1;
            }
        }
    }
    cout << cnt(1) - cnt(0) << endl; //所有情况-不包含100的情况=包含100的情况
    return 0;
}