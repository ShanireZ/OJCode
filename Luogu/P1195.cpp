#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int x, y, z;
    bool operator<(const Edge oth) const
    {
        return z < oth.z;
    }
};
Edge es[10005];
int g[1005];
int find(int x)
{
    if (x != g[x])
    {
        g[x] = find(g[x]);
    }
    return g[x];
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].x >> es[i].y >> es[i].z;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    sort(es + 1, es + 1 + m);
    int cnt = 0, tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int gx = find(es[i].x), gy = find(es[i].y);
        if (gx != gy)
        {
            g[gx] = gy, cnt++, tot += es[i].z;
        }
        if (cnt == n - k)
        {
            break;
        }
    }
    if (cnt != n - k)
    {
        cout << "No Answer" << endl;
    }
    else
    {
        cout << tot << endl;
    }
    return 0;
}