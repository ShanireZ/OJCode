#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int a, b, c;
    bool operator<(const Edge &oth) const
    {
        return c > oth.c;
    }
};
Edge es[100005];
int g[20005], v[20005], ans, n, m; // v[x]=0表示x与g[x]同屋,反之异屋
int dfn(int x)
{
    if (x != g[x])
    {
        int f = g[x];
        g[x] = dfn(g[x]);
        v[x] = v[x] ^ v[f];
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
        cin >> es[i].a >> es[i].b >> es[i].c;
    }
    sort(es + 1, es + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int a = es[i].a, b = es[i].b;
        int ga = dfn(a), gb = dfn(b);
        if (ga != gb)
        {
            g[ga] = gb, v[ga] = v[a] ^ v[b] ^ 1;
        }
        else if (v[a] == v[b])
        {
            cout << es[i].c << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
// TAG: 带权并查集
// 种类并查集中有多少种就需要开几倍的并查集
// 带权并查集中有多少种就需要设立几种并查集的关系