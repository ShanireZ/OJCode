#include <algorithm>
#include <iostream>
using namespace std;
#define MX 10000005
int v[MX], lc[MX], rc[MX], fa[MX];
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
int main()
{
    int n = read(), root = 1;
    v[1] = read(), v[0] = 1e9;
    for (int i = 2; i <= n; i++)
    {
        v[i] = read();
        int now = root, ok = 0;
        while (v[now] < v[i])
        {
            if (rc[now] == 0)
            {
                rc[now] = i, fa[i] = now, ok = 1;
                break;
            }
            now = rc[now];
        }
        if (ok == 0)
        {
            int f = fa[now];
            fa[now] = rc[f] = i;
            fa[i] = f, lc[i] = now;
            if (now == root)
            {
                root = i;
            }
        }
    }
    long long ansl = 0, ansr = 0;
    for (long long i = 1; i <= n; i++)
    {
        ansl = ansl ^ (i * (lc[i] + 1));
        ansr = ansr ^ (i * (rc[i] + 1));
    }
    printf("%lld %lld\n", ansl, ansr);
    return 0;
}