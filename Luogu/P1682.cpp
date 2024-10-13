#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int g[255], gx[100005][2];
set<int> s[255];
int dfn(int x)
{
    return x == g[x] ? x : g[x] = dfn(g[x]);
}
int main()
{
    int n, m, k, f;
    cin >> n >> m >> k >> f;
    for (int i = 1; i <= m; i++)
    {
        cin >> gx[i][0] >> gx[i][1];
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= f; i++) // 先合并女生朋友关系
    {
        int x, y;
        cin >> x >> y;
        int gx = dfn(x), gy = dfn(y);
        g[gx] = gy;
    }
    for (int i = 1; i <= m; i++) // 统计每组女生能选哪些男生
    {
        s[dfn(gx[i][0])].insert(gx[i][1]);
    }
    int res = 1e9;
    for (int i = 1; i <= n; i++) // 找到选择最少的组
    {
        if (s[i].size())
        {
            res = min(res, (int)s[i].size());
        }
    }
    cout << min(res + k, n) << endl;
    return 0;
}