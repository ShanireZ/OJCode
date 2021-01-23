#include <iostream>
using namespace std;
int g[2005];
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    int n, m, tot = 0;
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        char t;
        int x, y;
        cin >> t >> x >> y;
        int ax = dfn(x), ay = dfn(y);
        int bx = dfn(x + n), by = dfn(y + n);
        if (t == 'F')
        {
            g[ax] = ay;
        }
        else
        {
            g[bx] = ay;
            g[by] = ax;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == i)
        {
            tot++;
        }
    }
    cout << tot;
    return 0;
}