#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int x, y, r;
};
Node ns[5005];
struct Edge
{
    int u, v;
    double w;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
vector<Edge> es;
int n, g[5005];
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
        cin >> ns[i].x >> ns[i].y >> ns[i].r;
        for (int j = 1; j < i; j++)
        {
            double dis = sqrt((ns[i].x - ns[j].x) * (ns[i].x - ns[j].x) + (ns[i].y - ns[j].y) * (ns[i].y - ns[j].y));
            if (dis <= ns[i].r + ns[j].r)
            {
                g[find(j)] = i;
            }
            else
            {
                es.push_back(Edge{i, find(j), dis - ns[i].r - ns[j].r});
            }
        }
    }
    sort(es.begin(), es.end());
    double ans = 0;
    for (Edge e : es)
    {
        int u = find(e.u), v = find(e.v);
        if (u != v)
        {
            g[u] = v;
            ans += e.w;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}