#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int x, y, z;
};
Edge es[200005];
bool cmp(Edge a, Edge b)
{
    return a.z < b.z;
}
int n, m, ans, cnt, g[200005];
int find(int x)
{
    return g[x] == x ? x : g[x] = find(g[x]);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].x >> es[i].y >> es[i].z;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    sort(es + 1, es + m + 1, cmp), cnt = n - 1;
    for (int i = 1; i <= m; i++)
    {
        int gx = find(es[i].x), gy = find(es[i].y);
        if (gx != gy)
        {
            g[gx] = gy, ans = max(ans, es[i].z), cnt--;
        }
    }
    cout << (cnt == 0 ? ans : -1) << endl;
    return 0;
}