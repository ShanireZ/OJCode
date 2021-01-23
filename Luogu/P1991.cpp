#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
struct Line
{
    int x, y;
    double c;
};
Line ways[250005];
int g[505];
int pos[505][2];
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
    int s, p;
    cin >> s >> p;
    int t = 0;
    for (int i = 1; i <= p; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
        for (int j = i - 1; j >= 1; j--)
        {
            ways[t].x = i;
            ways[t].y = j;
            ways[t].c = pow(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2), 0.5);
            t++;
        }
        g[i] = i;
    }
    sort(ways, ways + t, cmp);
    int tot = 0;
    double maxn = 0;
    for (int i = 0; i < t && tot < p - s; i++)
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
    cout << fixed << setprecision(2) << maxn;
    return 0;
}