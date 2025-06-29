#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    long long x, y;
    bool operator<(const Node &oth) const
    {
        return x == oth.x ? y < oth.y : x < oth.x;
    }
};
Node ns[100005];
struct Edge
{
    long long u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
Edge es[3000005];
int n, epos, g[100005];
int find(int x)
{
    return g[x] == x ? x : g[x] = find(g[x]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
        cin >> ns[i].x >> ns[i].y;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n && j <= i + 30; j++)
        {
            es[++epos] = Edge{i, j, (ns[i].x - ns[j].x) * (ns[i].x - ns[j].x) + (ns[i].y - ns[j].y) * (ns[i].y - ns[j].y)};
        }
    }
    sort(es + 1, es + epos + 1);
    long long ans = 0;
    for (int i = 1; i <= epos; i++)
    {
        int gx = find(es[i].u), gy = find(es[i].v);
        if (gx != gy)
        {
            g[gx] = gy, ans += es[i].w;
        }
    }
    cout << ans << endl;
    return 0;
}