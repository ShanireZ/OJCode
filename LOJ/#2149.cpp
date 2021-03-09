#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Line
{
    int x, y, c;
};
Line ways[100005];
int g[305];
bool cmp(Line a, Line b)
{
    return a.c < b.c;
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> ways[i].x >> ways[i].y >> ways[i].c;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    sort(ways, ways + m, cmp);
    int tot = 0, maxn = 0;
    for (int i = 0; i < m; i++)
    {
        int gx = gfind(ways[i].x);
        int gy = gfind(ways[i].y);
        if (gx != gy)
        {
            g[gx] = gy;
            tot++;
            maxn = ways[i].c;
        }
    }
    cout << tot << " " << maxn;
    return 0;
}