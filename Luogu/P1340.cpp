#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int x, y, z, id;
    bool operator<(const Edge oth) const
    {
        return z < oth.z;
    }
};
Edge es[6005];
int g[205];
int find(int x)
{
    if (g[x] != x)
    {
        g[x] = find(g[x]);
    }
    return g[x];
}
int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= w; i++)
    {
        cin >> es[i].x >> es[i].y >> es[i].z;
        es[i].id = i;
    }
    sort(es + 1, es + 1 + w);
    for (int times = 1; times <= w; times++)
    {
        for (int i = 1; i <= n; i++)
        {
            g[i] = i;
        }
        int cnt = 0, tot = 0;
        for (int i = 1; i <= w; i++)
        {
            if (es[i].id > times)
            {
                continue;
            }
            int gx = find(es[i].x), gy = find(es[i].y);
            if (gx != gy)
            {
                g[gx] = gy, cnt++, tot += es[i].z;
            }
        }
        if (cnt != n - 1)
        {
            tot = -1;
        }
        cout << tot << endl;
    }
    return 0;
}