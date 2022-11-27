#include <iostream>
using namespace std;
long long read(), a[1005][1005], b[55][55];
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = read();
        }
    }
    int r = read(), c = read();
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            b[i][j] = read();
        }
    }
    for (int i = 1; i <= n; i++) // 统计每个颜色的二维前缀和
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] += (i > r ? a[i - r][j] : 0);
            a[i][j] += (j > c ? a[i][j - c] : 0);
            a[i][j] -= (i > r && j > c ? a[i - r][j - c] : 0);
        }
    }
    int q = read();
    while (q--)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        long long ans = 0;
        for (int i = 0; i < r && x2 - i >= x1; i++)
        {
            for (int j = 0; j < c && y2 - j >= y1; j++)
            {
                int x = x2 - i, y = y2 - j;
                if (b[(x - x1) % r + 1][(y - y1) % c + 1] == 1)
                {
                    continue;
                }
                long long bx = (x - x1) / r + 1, by = (y - y1) / c + 1;
                ans += a[x][y];
                ans -= (x - bx * r > 0 ? a[x - bx * r][y] : 0);
                ans -= (y - by * c > 0 ? a[x][y - by * c] : 0);
                ans += (x - bx * r > 0 && y - by * c > 0 ? a[x - bx * r][y - by * c] : 0);
            }
        }
        printf("%lld\n", ans % 998244353);
    }
    return 0;
}
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}