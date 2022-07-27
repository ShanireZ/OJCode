#include <algorithm>
#include <cstdio>
using namespace std;
int dpmax[1005][1005], dpmin[1005][1005];
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
int main()
{
    int a = read(), b = read(), n = read();
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            int now = read();
            dpmax[i][j] = dpmin[i][j] = now;
        }
    }
    for (int k = 2; k <= n; k++)
    {
        for (int i = a; i >= k; i--)
        {
            for (int j = b; j >= k; j--)
            {
                dpmax[i][j] = max(dpmax[i][j], max(dpmax[i - 1][j], max(dpmax[i - 1][j - 1], dpmax[i][j - 1])));
                dpmin[i][j] = min(dpmin[i][j], min(dpmin[i - 1][j], min(dpmin[i - 1][j - 1], dpmin[i][j - 1])));
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = n; i <= a; i++)
    {
        for (int j = n; j <= b; j++)
        {
            ans = min(ans, dpmax[i][j] - dpmin[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}