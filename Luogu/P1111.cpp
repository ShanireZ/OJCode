#include <iostream>
#include <algorithm>
using namespace std;
int g[1005];
struct Road
{
    int x, y, t;
};
Road road[100005];
bool cmp(Road a, Road b)
{
    return a.t < b.t;
}
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> road[i].x >> road[i].y >> road[i].t;
    }
    sort(road + 1, road + 1 + m, cmp);
    int tot = n;
    for (int i = 1; i <= m; i++)
    {
        int gx = dfn(road[i].x), gy = dfn(road[i].y);
        if (gx != gy)
        {
            tot--;
            g[gx] = gy;
            if (tot == 1)
            {
                cout << road[i].t;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}