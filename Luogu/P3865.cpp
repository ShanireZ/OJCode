#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int st[20][100005];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        st[0][i] = read();
    }
    for (int h = 1; h <= log2(n); h++)
    {
        int len = pow(2, h - 1);
        for (int i = 1; i <= n; i++)
        {
            st[h][i] = max(st[h - 1][i], st[h - 1][i + len]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        int len = r - l + 1;
        int x = log2(len);
        int part = pow(2, x);
        printf("%d\n", max(st[x][l], st[x][r - part + 1]));
    }
    return 0;
}