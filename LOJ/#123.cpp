#include <cstdio>
#include <algorithm>
using namespace std;
struct Line
{
    int u, v, w;
};
Line ls[500005];
int g[200005];
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }

    return g[x];
}
bool cmp(Line a, Line b)
{
    return a.w < b.w;
}
int read();
int main()
{
    int n = read(), m = read();

    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        ls[i].u = read();
        ls[i].v = read();
        ls[i].w = read();
    }

    sort(ls + 1, ls + 1 + m, cmp);
    long long tot = 0;

    for (int i = 1; i <= m; i++)
    {
        int gx = dfn(ls[i].u), gy = dfn(ls[i].v);

        if (gx != gy)
        {
            g[gx] = gy;
            tot += ls[i].w;
        }
    }

    printf("%lld", tot);
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();

    while (ch != '-' && ch > '9' || ch < '0')
    {
        ch = getchar();
    }

    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }

    return ans * type;
}