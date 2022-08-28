#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge oth) const
    {
        return w < oth.w;
    }
};
Edge es[3005];
int g[2005], tot, n, m;
int dfn(int now)
{
    return (now == g[now]) ? now : g[now] = dfn(g[now]);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].w;
    }
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int ga = dfn(es[i].u), gb = dfn(es[i].v);
        if (ga != gb)
        {
            tot += es[i].w;
            g[ga] = gb;
        }
    }
    cout << tot << endl;
    return 0;
}