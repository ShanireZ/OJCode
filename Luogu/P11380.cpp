#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, bool> mp;
int n, m, pre[200005], nxt[200005], g[200005];
int dfn(int x)
{
    return (x == g[x] ? x : g[x] = dfn(g[x]));
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    int cnt = n;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (mp[{a, b}]) // 有重复且相同的关系
        {
            continue;
        }
        mp[{a, b}] = 1;
        int ga = dfn(a), gb = dfn(b);
        if (pre[b] || nxt[a] || ga == gb)
        {
            cout << 0 << endl;
            return 0;
        }
        pre[b] = a, nxt[a] = b, g[gb] = ga, cnt--;
    }
    long long ans = 1;
    for (int i = 2; i <= cnt; i++)
    {
        ans = ans * i % 1000000007;
    }
    cout << ans << endl;
    return 0;
}