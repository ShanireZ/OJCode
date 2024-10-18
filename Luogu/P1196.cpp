#include <algorithm>
#include <iostream>
using namespace std;
int g[30005], sz[30005], v[30005]; // v[x]:x到g[x]的距离
int dfn(int x)
{
    if (x != g[x])
    {
        int f = g[x];
        g[x] = dfn(g[x]);
        v[x] += v[f];
    }
    return g[x];
}
int main()
{
    for (int i = 1; i <= 30000; i++)
    {
        g[i] = i, sz[i] = 1;
    }
    int p;
    cin >> p;
    while (p--)
    {
        char opt;
        int x, y;
        cin >> opt >> x >> y;
        int gx = dfn(x), gy = dfn(y);
        if (opt == 'M')
        {
            v[gx] += sz[gy];
            g[gx] = gy, sz[gy] += sz[gx];
        }
        else
        {
            if (gx == gy)
            {
                cout << abs(v[x] - v[y]) - 1 << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    return 0;
}
// TAG: 权值并查集