#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
inline int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
set<int> all[100005];
int g[100005], cnt;
inline int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
inline long long cntCost(int x, int gid)
{
    long long cost = 1e15;
    auto itr = all[gid].lower_bound(x);
    auto itl = itr;
    if (itl != all[gid].begin())
    {
        itl--;
    }
    cost = min(cost, 1ll * (x - *itl) * (x - *itl));
    if (itr != all[gid].end())
    {
        cost = min(cost, 1ll * (x - *itr) * (x - *itr));
    }
    return cost;
}
int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), m = read();
        for (int i = 1; i <= n; i++)
        {
            g[i] = i;
            all[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read();
            int gu = dfn(u), gv = dfn(v);
            if (gu != gv)
            {
                g[gu] = gv;
            }
        }
        if (dfn(1) == dfn(n))
        {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            int x = dfn(i);
            all[x].insert(i);
        }
        long long ans = 1e15;
        int g1 = dfn(1), gn = dfn(n);
        for (int i = 1; i <= n; i++) //每个组遍历
        {
            long long cost1 = 1e15, costn = 1e15;
            for (auto j = all[i].begin(); j != all[i].end(); j++) //组内数遍历
            {
                cost1 = min(cost1, cntCost(*j, g1));
                costn = min(costn, cntCost(*j, gn));
            }
            ans = min(ans, cost1 + costn);
        }
        printf("%lld\n", ans);
    }
    return 0;
}