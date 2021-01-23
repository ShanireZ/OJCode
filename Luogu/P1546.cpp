#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Line
{
    int x, y, v;
};
Line ways[10005];
int g[105];
bool cmp(Line a, Line b)
{
    return a.v < b.v;
}
int gfind(int x)
{
    if (x == g[x])
    {
        return g[x];
    }
    g[x] = gfind(g[x]);
    return g[x];
}
int main()
{
    int n;
    cin >> n;
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ways[p].v;
            ways[p].x = i;
            ways[p].y = j;
            p++;
        }
        g[i] = i;
    }
    sort(ways, ways + p, cmp);
    int tot = 0, ans = 0;
    for (int i = 0; i < p && tot < n - 1; i++)
    {
        int gx = gfind(ways[i].x);
        int gy = gfind(ways[i].y);
        if (gx != gy)
        {
            g[gx] = gy;
            tot++;
            ans += ways[i].v;
        }
    }
    cout << ans;
    return 0;
}