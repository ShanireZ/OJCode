#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
long long g[50], f[9000000], n, w, ans, pos;
void dfs(int now, long long tot)
{
    if (now > n / 2)
    {
        f[++pos] = tot;
        return;
    }
    if (tot + g[now] <= w)
    {
        dfs(now + 1, tot + g[now]);
    }
    dfs(now + 1, tot);
}
void dfs2(int now, long long tot)
{
    if (now > n)
    {
        int p = upper_bound(f + 1, f + 1 + pos, w - tot) - f - 1;
        ans = max(ans, f[p] + tot);
        return;
    }
    if (tot + g[now] <= w)
    {
        dfs2(now + 1, tot + g[now]);
    }
    dfs2(now + 1, tot);
}
int main()
{
    cin >> w >> n;
    w--;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
    }
    dfs(1, 0);
    sort(f + 1, f + 1 + pos);
    dfs2(n / 2 + 1, 0);
    cout << ans << endl;
    return 0;
}