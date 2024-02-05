#include <algorithm>
#include <iostream>
using namespace std;
long long a[50], fa[1000005], n, m, pos, ans;
void dfs1(int now, long long tot)
{
    if (now > n / 2)
    {
        fa[pos++] = tot;
        return;
    }
    dfs1(now + 1, tot);
    dfs1(now + 1, (tot + a[now]) % m);
}
void dfs2(int now, long long tot)
{
    if (now > n)
    {
        int x = upper_bound(fa, fa + pos, m - 1 - tot) - fa;
        if (x != 0)
        {
            ans = max(ans, fa[x - 1] + tot);
        }
        ans = max(ans, (tot + fa[pos - 1]) % m);
        return;
    }
    dfs2(now + 1, tot);
    dfs2(now + 1, (tot + a[now]) % m);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs1(1, 0);
    sort(fa, fa + pos);
    dfs2(n / 2 + 1, 0);
    cout << ans << endl;
    return 0;
}