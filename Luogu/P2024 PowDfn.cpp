#include <algorithm>
#include <iostream>
using namespace std;
int g[50005], v[50005], n, m, ans; // v[x]:0同类 1吃g[x] 2被g[x]吃
int dfn(int x)
{
    if (x != g[x])
    {
        int f = g[x];
        g[x] = dfn(g[x]);
        v[x] = (v[x] + v[f]) % 3;
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
        int opt, x, y;
        cin >> opt >> x >> y;
        if (x > n || y > n || (opt == 2 && x == y))
        {
            ans++;
            continue;
        }
        int gx = dfn(x), gy = dfn(y);
        if (opt == 1)
        {
            if (gx != gy)
            {
                g[gx] = gy, v[gx] = (v[y] - v[x] + 3) % 3;
            }
            else if (v[x] != v[y])
            {
                ans++;
            }
        }
        else
        {
            if (gx != gy)
            {
                g[gx] = gy, v[gx] = (v[y] + 4 - v[x]) % 3;
            }
            else if (v[x] != (v[y] + 1) % 3)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}