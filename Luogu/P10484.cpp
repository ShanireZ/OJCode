#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<long long> f;
long long g[50], n, w, ans;
void dfs1(int now, long long tot)
{
    if (now > n / 2)
    {
        f.push_back(tot);
        return;
    }
    if (g[now] + tot <= w)
    {
        dfs1(now + 1, tot + g[now]);
    }
    dfs1(now + 1, tot);
}
void dfs2(int now, long long tot)
{
    if (now > n)
    {
        long long x = w - tot;
        int p = upper_bound(f.begin(), f.end(), x) - f.begin();
        if (p != 0)
        {
            ans = max(ans, f[p - 1] + tot);
        }
        return;
    }
    if (g[now] + tot <= w)
    {
        dfs2(now + 1, tot + g[now]);
    }
    dfs2(now + 1, tot);
}
int main()
{
    cin >> w >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
    }
    dfs1(1, 0);
    sort(f.begin(), f.end());
    dfs2(n / 2 + 1, 0);
    cout << ans << endl;
    return 0;
}