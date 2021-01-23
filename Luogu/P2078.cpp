#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> g, cnt;
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
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = -m; i <= n; i++)
    {
        g[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i <= p + q; i++)
    {
        int x, y;
        cin >> x >> y;
        int gx = dfn(x), gy = dfn(y);
        if (gx != gy)
        {
            cnt[gy] += cnt[gx];
            g[gx] = gy;
        }
    }
    int nan = dfn(1), nv = dfn(-1);
    cout << min(cnt[nan], cnt[nv]);
    return 0;
}