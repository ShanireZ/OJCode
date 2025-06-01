#include <algorithm>
#include <iostream>
using namespace std;
int n, m, g[10005], v[10005];
int dfn(int x)
{
    if (x != g[x])
    {
        int fa = g[x];
        g[x] = dfn(g[x]);
        if (g[x] != fa)
        {
            v[x] += v[fa];
        }
    }
    return g[x];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            int fa = dfn(a), fb = dfn(b);
            if (fa != fb)
            {
                g[fa] = fb, v[fa] -= v[fb];
            }
        }
        else
        {
            v[dfn(a)] += b;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int fi = dfn(i);
        cout << (g[i] == i ? v[i] : v[i] + v[fi]) << " ";
    }
    return 0;
}