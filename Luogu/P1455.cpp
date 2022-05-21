#include <iostream>
using namespace std;
struct Node
{
    int p, v;
};
Node ns[10005];
int g[10005], dp[10005];
int dfn(int now)
{
    if (g[now] != now)
    {
        g[now] = dfn(g[now]);
    }
    return g[now];
}
int main()
{
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
        cin >> ns[i].p >> ns[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        int gx = dfn(x), gy = dfn(y);
        if (gx != gy)
        {
            g[gx] = gy;
            ns[gy].p += ns[gx].p;
            ns[gy].v += ns[gx].v;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i] != i)
        {
            continue;
        }
        for (int j = w; j >= ns[i].p; j--)
        {
            dp[j] = max(dp[j], dp[j - ns[i].p] + ns[i].v);
        }
    }
    cout << dp[w] << endl;
    return 0;
}