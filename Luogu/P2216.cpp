#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int stmax[1005][1005][15], stmin[1005][1005][15];
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
            stmax[i][j][0] = stmin[i][j][0] = now;
        }
    }
    int maxp = log2(n);
    for (int p = 1; p <= maxp; p++)
    {
        int ex = pow(2, p);
        for (int i = ex; i <= a; i++)
        {
            for (int j = ex; j <= b; j++)
            {
                int ans1 = max(stmax[i][j][p - 1], stmax[i - ex / 2][j - ex / 2][p - 1]);
                int ans2 = max(stmax[i - ex / 2][j][p - 1], stmax[i][j - ex / 2][p - 1]);
                stmax[i][j][p] = max(ans1, ans2);
                ans1 = min(stmin[i][j][p - 1], stmin[i - ex / 2][j - ex / 2][p - 1]);
                ans2 = min(stmin[i - ex / 2][j][p - 1], stmin[i][j - ex / 2][p - 1]);
                stmin[i][j][p] = min(ans1, ans2);
            }
        }
    }
    int ans = 0x3f3f3f3f, ex = pow(2, maxp);
    for (int i = n; i <= a; i++)
    {
        for (int j = n; j <= b; j++)
        {
            int ans1 = max(stmax[i][j][maxp], stmax[i - n + ex][j - n + ex][maxp]);
            int ans2 = max(stmax[i - n + ex][j][maxp], stmax[i][j - n + ex][maxp]);
            int ans3 = min(stmin[i][j][maxp], stmin[i - n + ex][j - n + ex][maxp]);
            int ans4 = min(stmin[i - n + ex][j][maxp], stmin[i][j - n + ex][maxp]);
            ans = min(ans, max(ans1, ans2) - min(ans3, ans4));
        }
    }
    printf("%d\n", ans);
    return 0;
}