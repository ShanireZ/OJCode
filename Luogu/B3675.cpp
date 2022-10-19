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
};
int ans[500005][2], a[1005];
long long v[1005];
int main()
{
    int m = read(), n = read();
    for (int t = 1; t <= 2; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            long long tot = 0;
            for (int j = 1; j <= m; j++)
            {
                a[j] = read();
                tot += a[j];
            }
            for (int j = 1; j <= m; j++)
            {
                v[i] += (a[j] * m - tot) * (a[j] * m - tot);
            }
        }
    }
    int cnt = 0;
    for (int i = n; i > 1; i--)
    {
        for (int now = 1; now < i; now++)
        {
            if (v[now] > v[now + 1])
            {
                ans[++cnt][0] = now, ans[cnt][1] = now + 1;
                swap(v[now], v[now + 1]);
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}