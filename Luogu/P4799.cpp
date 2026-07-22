#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, pos, ans, a[45], f[2000005];
void dfs1(int now, long long tot)
{
    if (now > n / 2)
    {
        f[++pos] = tot;
        return;
    }
    dfs1(now + 1, tot + a[now]);
    dfs1(now + 1, tot);
}
void dfs2(int now, long long tot)
{
    if (now > n)
    {
        long long res = m - tot;
        int p = upper_bound(f + 1, f + 1 + pos, res) - f;
        ans += p - 1;
        return;
    }
    dfs2(now + 1, tot + a[now]);
    dfs2(now + 1, tot);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs1(1, 0);
    sort(f + 1, f + 1 + pos);
    dfs2(n / 2 + 1, 0);
    cout << ans << endl;
    return 0;
}