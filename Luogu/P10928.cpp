#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w;
};
vector<Edge> es;
int n, t, g[6005], sz[6005];
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
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            es.push_back(Edge{x, y, z});
            g[i] = i, sz[i] = 1;
        }
        g[n] = n, sz[n] = 1;
        sort(es.begin(), es.end(), cmp);
        int ans = 0;
        for (int i = 0; i < es.size(); i++)
        {
            int gu = find(es[i].u), gv = find(es[i].v);
            if (gu != gv)
            {
                ans += (es[i].w + 1) * (sz[gu] * sz[gv] - 1);
                g[gu] = gv, sz[gv] += sz[gu];
            }
        }
        cout << ans << endl;
        es.clear();
    }
    return 0;
}