#include <cstring>
#include <iostream>
using namespace std;
#define MX 505
long long d[MX][MX], va[MX], vb[MX], c;
int n, m, epos, pos, visa[MX], visb[MX], back[MX];
long long read()
{
    long long ans = 0, f = 1;
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
bool dfs(int now, int turn)
{
    if (visa[now] == turn)
    {
        return 0;
    }
    visa[now] = turn;
    for (int t = 1; t <= n; t++)
    {
        if (d[now][t] == -0x3f3f3f3f3f3f3f3f)
        {
            continue;
        }
        if (d[now][t] == va[now] + vb[t])
        {
            visb[t] = turn;
            if (back[t] == 0 || dfs(back[t], turn))
            {
                back[t] = now;
                return 1;
            }
        }
        else
        {
            c = min(c, va[now] + vb[t] - d[now][t]);
        }
    }
    return 0;
}
int main()
{
    n = read(), m = read();
    memset(d, -0x3f, sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        int y = read(), c = read();
        d[y][c] = max(d[y][c], read());
        va[y] = max(va[y], d[y][c]);
    }
    for (int i = 1; i <= n; i++)
    {
        c = 0x3f3f3f3f3f3f3f3f;
        while (dfs(i, ++pos) == false)
        {
            for (int i = 1; i <= n; i++)
            {
                if (visa[i] == pos)
                {
                    va[i] -= c;
                }
                if (visb[i] == pos)
                {
                    vb[i] += c;
                }
            }
            c = 0x3f3f3f3f3f3f3f3f;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans + va[i] + vb[i];
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << back[i] << " ";
    }
    return 0;
}