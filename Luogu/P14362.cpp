#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
Edge es[10250000], oes[1000005];
int n, m, k, epos, c[15], g[10015];
int dfn(int x)
{
    return x == g[x] ? x : g[x] = dfn(g[x]);
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        oes[i] = Edge{u, v, w};
    }
    sort(oes + 1, oes + m + 1);
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int gu = dfn(oes[i].u), gv = dfn(oes[i].v);
        if (gu != gv)
        {
            ans += oes[i].w, g[gu] = gv, es[++epos] = oes[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            es[++epos] = Edge{n + i + 1, j, w};
        }
    }
    sort(es + 1, es + epos + 1);
    for (int sta = 1; sta < (1 << k); sta++)
    {
        long long res = 0;
        for (int i = 1; i <= n + k; i++)
        {
            g[i] = i;
        }
        for (int i = 1; i <= epos; i++)
        {
            int p = es[i].u - n - 1;
            if (p < 0 || (sta & (1 << p)))
            {
                int gu = dfn(es[i].u), gv = dfn(es[i].v);
                if (gu != gv)
                {
                    res += es[i].w, g[gu] = gv;
                }
            }
        }
        for (int i = 0, t = sta; t != 0; i++, t /= 2)
        {
            if (t % 2 == 1)
            {
                res += c[i];
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}