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
long long n, x[1005], y[1005], g[1005];
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int find(int x)
{
    return (x == g[x] ? x : g[x] = find(g[x]));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++)
        {
            double w = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            es.push_back(Edge{i, j, w});
        }
        g[i] = i;
    }
    sort(es.begin(), es.end(), cmp);
    for (int i = 0, cnt = 0; i < es.size(); i++)
    {
        int gu = find(es[i].u), gv = find(es[i].v);
        if (gu != gv)
        {
            cnt++;
            g[gu] = gv;
        }
        if (cnt == n - 1)
        {
            cout << fixed << setprecision(7) << es[i].w / 2 << endl;
            break;
        }
    }
    return 0;
}