#include <iostream>
#include <map>
using namespace std;
int n, m, ans = 100;
long long trans[40], fal;
map<long long, int> mp;
void dfs1(int now, int t, long long state)
{
    if (now > n / 2)
    {
        mp[state] = (mp[state] == 0 && state != 0) ? t : min(mp[state], t);
        return;
    }
    dfs1(now + 1, t, state);
    dfs1(now + 1, t + 1, state ^ trans[now]);
}
void dfs2(int now, int t, long long state)
{
    if (now > n)
    {
        if (mp[fal ^ state] == 0 && state != fal)
        {
            return;
        }
        ans = min(ans, mp[fal ^ state] + t);
        return;
    }
    dfs2(now + 1, t, state);
    dfs2(now + 1, t + 1, state ^ trans[now]);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        trans[i] = (1ll << i);
        fal += trans[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        trans[a] = trans[a] | (1ll << b);
        trans[b] = trans[b] | (1ll << a);
    }
    dfs1(1, 0, 0);
    dfs2(n / 2 + 1, 0, 0);
    cout << ans << endl;
    return 0;
}