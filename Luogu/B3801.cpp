#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int read()
{
    int ans = 0;
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
int prim[3500], vis[3500], pos;
long long dp[500][500];
int main()
{
    for (int i = 2; i <= 3200; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= 3200; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= pos; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j; // 第二类斯特林数
        }
    }
    int t = read();
    while (t--)
    {
        int n = read(), k = read(), cnt = 0;
        for (int i = 1; i <= pos; i++)
        {
            int ok = 0;
            while (n % prim[i] == 0)
            {
                ok = 1;
                n /= prim[i];
            }
            cnt += ok;
        }
        cnt += (n > 1);
        if (k > cnt)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n", dp[cnt][k]);
        }
    }
    return 0;
}