#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define MX 100005
int afmin[MX][20], afmax[MX][20], azmin[MX][20], azmax[MX][20], bmax[MX][20], bmin[MX][20];
int n, m, q, a[MX], b[MX];
int read()
{
    int ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}
int main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        if (a[i] < 0)
        {
            afmin[i][0] = afmax[i][0] = a[i];
            azmax[i][0] = -1, azmin[i][0] = 0x3f3f3f3f;
        }
        else
        {
            azmin[i][0] = azmax[i][0] = a[i];
            afmax[i][0] = -0x3f3f3f3f, afmin[i][0] = 0;
        }
    }
    for (int j = 1; j <= log2(n); j++)
    {
        for (int i = 1; i + pow(2, j) - 1 <= n; i++)
        {
            int pos = i + pow(2, j - 1);
            afmin[i][j] = min(afmin[i][j - 1], afmin[pos][j - 1]);
            azmin[i][j] = min(azmin[i][j - 1], azmin[pos][j - 1]);
            afmax[i][j] = max(afmax[i][j - 1], afmax[pos][j - 1]);
            azmax[i][j] = max(azmax[i][j - 1], azmax[pos][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        bmax[i][0] = bmin[i][0] = b[i] = read();
    }
    for (int j = 1; j <= log2(m); j++)
    {
        for (int i = 1; i + pow(2, j) - 1 <= m; i++)
        {
            int pos = i + pow(2, j - 1);
            bmax[i][j] = max(bmax[i][j - 1], bmax[pos][j - 1]);
            bmin[i][j] = min(bmin[i][j - 1], bmin[pos][j - 1]);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int l1 = read(), r1 = read(), l2 = read(), r2 = read();
        int x = log2(r2 - l2 + 1);
        int pos = r2 - pow(2, x) + 1;
        long long ans1 = max(bmax[l2][x], bmax[pos][x]), ans2 = min(bmin[l2][x], bmin[pos][x]);
        x = log2(r1 - l1 + 1);
        pos = r1 - pow(2, x) + 1;
        long long opt = -0x3f3f3f3f3f3f3f3f;
        if (afmax[l1][x] != -0x3f3f3f3f)
        {
            opt = max(opt, max(afmax[l1][x] * ans1, afmin[l1][x] * ans1));
        }
        if (azmin[l1][x] != 0x3f3f3f3f)
        {
            opt = max(opt, max(azmax[l1][x] * ans2, azmin[l1][x] * ans2));
        }
        if (afmax[pos][x] != -0x3f3f3f3f)
        {
            opt = max(opt, max(afmax[pos][x] * ans1, afmin[pos][x] * ans1));
        }
        if (azmin[pos][x] != 0x3f3f3f3f)
        {
            opt = max(opt, max(azmax[pos][x] * ans2, azmin[pos][x] * ans2));
        }
        printf("%lld\n", opt);
    }
    return 0;
}