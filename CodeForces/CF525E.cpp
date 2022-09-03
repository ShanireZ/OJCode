#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> dp[30]; // dp[a][b] 使用a个阶乘变换,和为b的方案数
int n, k;
long long s, ans, a[30], jc[20];
void dfs1(int now, int t, long long tot)
{
    if (tot > s)
    {
        return;
    }
    if (now > n / 2)
    {
        dp[t][tot]++;
        return;
    }
    dfs1(now + 1, t, tot + a[now]);
    dfs1(now + 1, t, tot);
    if (t + 1 <= k && a[now] <= 18)
    {
        dfs1(now + 1, t + 1, tot + jc[a[now]]);
    }
}
void dfs2(int now, int t, long long tot)
{
    if (tot > s)
    {
        return;
    }
    if (now > n)
    {
        for (int x = k - t; x >= 0; x--)
        {
            ans += dp[x][s - tot];
        }
        return;
    }
    dfs2(now + 1, t, tot + a[now]);
    dfs2(now + 1, t, tot);
    if (t + 1 <= k && a[now] <= 18)
    {
        dfs2(now + 1, t + 1, tot + jc[a[now]]);
    }
}
int main()
{
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    jc[0] = 1;
    for (int i = 1; i < 20; i++)
    {
        jc[i] = jc[i - 1] * i;
    }
    dfs1(1, 0, 0);
    dfs2(n / 2 + 1, 0, 0);
    cout << ans << endl;
    return 0;
}