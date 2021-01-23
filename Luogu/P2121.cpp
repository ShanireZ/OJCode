#include <iostream>
#include <algorithm>
using namespace std;
struct Line
{
    int u, v, w;
};
Line ls[100005];
bool cmp(Line a, Line b)
{
    return a.w > b.w;
}
int g[100005];
int dfs(int x)
{
    if (x != g[x])
    {
        g[x] = dfs(g[x]);
    }
    return g[x];
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ls[i].u >> ls[i].v >> ls[i].w;
    }
    sort(ls + 1, ls + 1 + m, cmp);
    int ans = 0, tot = 0;
    for (int i = 1; i <= m && tot < k; i++)
    {
        int gx = dfs(ls[i].u);
        int gy = dfs(ls[i].v);
        if (gx != gy)
        {
            tot++;
            ans += ls[i].w;
            g[gx] = gy;
        }
    }
    cout << ans;
    return 0;
}