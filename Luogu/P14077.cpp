#include <algorithm>
#include <iostream>
using namespace std;
int n, m, cnt, g[100005];
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
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
        int u, v;
        cin >> u >> v;
        int gu = dfn(u), gv = dfn(v);
        if (gu != gv)
        {
            g[gu] = gv, cnt++;
        }
    }
    cout << n - 1 - cnt << endl;
    return 0;
}