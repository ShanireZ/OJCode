#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int a, b, c;
    bool operator<(const Node &oth) const
    {
        return c > oth.c;
    }
};
Node ns[100005];
int g[40005];
int dfn(int x)
{
    return g[x] == x ? x : g[x] = dfn(g[x]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].a >> ns[i].b >> ns[i].c;
    }
    sort(ns + 1, ns + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        int ga = dfn(ns[i].a), gb = dfn(ns[i].b);
        int fga = dfn(ns[i].a + n), fgb = dfn(ns[i].b + n);
        if (ga == gb)
        {
            cout << ns[i].c << endl;
            return 0;
        }
        g[ga] = fgb, g[gb] = fga;
    }
    cout << 0 << endl;
    return 0;
}
// TAG: 种类并查集