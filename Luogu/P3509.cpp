#include <algorithm>
#include <iostream>
using namespace std;
#define MX 1000005
long long read(), p[MX], ans[MX], pw[65], anc[MX][65];
int main()
{
    long long n = read(), k = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        p[i] = read(), ans[i] = i;
    }
    int l = 1, r = k + 1;
    for (int i = 1; i <= n; i++)
    {
        while (r < n && p[r + 1] - p[i] < p[i] - p[l])
        {
            l++, r++;
        }
        anc[i][0] = (p[r] - p[i] <= p[i] - p[l] ? l : r);
    }
    pw[0] = 1;
    for (int j = 1; j <= 60; j++)
    {
        pw[j] = pw[j - 1] * 2;
        for (int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    for (int j = 60; j >= 0 && m; j--)
    {
        if (pw[j] <= m)
        {
            m -= pw[j];
            for (int i = 1; i <= n; i++)
            {
                ans[i] = anc[ans[i]][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", ans[i]);
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
// TAG: 倍增 ST表