#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct Edge
{
    int a, b, c;
    bool operator<(const Edge &oth) const
    {
        return c > oth.c;
    }
};
Edge es[100005];
map<int, int> mp;
int g[200005], T, m, pos, trig;
int lsh(int x)
{
    if (mp[x] == 0)
    {
        mp[x] = ++pos;
        g[pos] = pos;
    }
    return mp[x];
}
int dfn(int x)
{
    return g[x] == x ? x : g[x] = dfn(g[x]);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        mp.clear(), pos = 0, trig = 1;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> es[i].a >> es[i].b >> es[i].c;
            es[i].a = lsh(es[i].a), es[i].b = lsh(es[i].b);
        }
        sort(es + 1, es + m + 1); // 先处理所有相同,再检查不同是否冲突
        for (int i = 1; i <= m; i++)
        {
            int ga = dfn(es[i].a), gb = dfn(es[i].b);
            if (es[i].c == 1)
            {
                g[ga] = gb;
            }
            else if (ga == gb)
            {
                trig = 0;
                break;
            }
        }
        cout << (trig ? "YES" : "NO") << '\n';
    }
    return 0;
}