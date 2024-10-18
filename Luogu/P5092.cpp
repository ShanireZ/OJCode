#include <algorithm>
#include <iostream>
using namespace std;
int g[30005], sz[30005], v[30005];
// sz记录当前集合大小 v记录当前方块x到g[x]的距离
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
        cin >> opt >> x;
        if (opt == 'M')
        {
            cin >> y;
            int gx = dfn(x), gy = dfn(y);
            v[gy] += sz[gx];
            g[gy] = gx, sz[gx] += sz[gy];
        }
        else
        {
            int gx = dfn(x);
            cout << sz[gx] - v[x] - 1 << '\n';
        }
    }
    return 0;
}
// TAG: 权值并查集