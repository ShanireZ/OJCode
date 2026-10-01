#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v;
    double w;
};
vector<Edge> es;
int n, l, x[505], y[505], g[505];
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int find(int x)
{
    return g[x] = (x == g[x] ? x : find(g[x]));
}
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++)
        {
            double w = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            if (w <= l)
            {
                es.push_back(Edge{i, j, w});
            }
        }
        g[i] = i;
    }
    sort(es.begin(), es.end(), cmp);
    double ans = 0;
    int cnt = 0;
    for (Edge e : es)
    {
        int gu = find(e.u), gv = find(e.v);
        if (gu != gv)
        {
            g[gu] = gv;
            ans += e.w, cnt++;
        }
    }
    if (cnt < n - 1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}