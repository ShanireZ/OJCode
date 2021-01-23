#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Line
{
    int x, y, w;
};
bool cmp(Line a, Line b)
{
    return a.w < b.w;
}
Line ls[20005];
int g[10005];
int dfs(int a)
{
    if (a != g[a])
    {
        g[a] = dfs(g[a]);
    }
    return g[a];
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        cin >> ls[i].x >> ls[i].y >> ls[i].w;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    sort(ls + 1, ls + 1 + m, cmp);
    int ans = 0, pos = 1;
    while (dfs(s) != dfs(t))
    {
        int gx = dfs(ls[pos].x);
        int gy = dfs(ls[pos].y);
        if (gx != gy)
        {
            g[gx] = gy;
            ans = max(ans, ls[pos].w);
        }
        pos++;
    }
    cout << ans;
    return 0;
}