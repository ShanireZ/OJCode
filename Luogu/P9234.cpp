#include <algorithm>
#include <bits/extc++.h>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
int n, m, pos, ans = 100;
long long a[35];
cc_hash_table<int, int> mp;
void dfs1(int now, int tot, int t)
{
    if (now > n / 2)
    {
        if (mp.find(tot) == mp.end())
        {
            mp[tot] = t;
        }
        else
        {
            mp[tot] = min(mp[tot], t);
        }
        return;
    }
    if (tot + a[now] <= m)
    {
        dfs1(now + 1, tot + a[now], t);
    }
    if (tot + a[now] / 2 <= m)
    {
        dfs1(now + 1, tot + a[now] / 2, t + 1);
    }
    dfs1(now + 1, tot, t);
}
void dfs2(int now, int tot, int t)
{
    if (now > n)
    {
        int res = m - tot;
        if (mp.find(res) != mp.end())
        {
            ans = min(ans, t + mp[res]);
        }
        return;
    }
    if (tot + a[now] <= m)
    {
        dfs2(now + 1, tot + a[now], t);
    }
    if (tot + a[now] / 2 <= m)
    {
        dfs2(now + 1, tot + a[now] / 2, t + 1);
    }
    dfs2(now + 1, tot, t);
}
int main()
{
    cin >> n >> m;
    m *= 2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a + 1, a + n + 1);
    dfs1(1, 0, 0);
    dfs2(n / 2 + 1, 0, 0);
    cout << (ans == 100 ? -1 : ans) << endl;
    return 0;
}