#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, l[100005], r[100005], wq[100005], dp[100005], sz[100005];
void dfs(int now)
{
    if (l[now])
    {
        dfs(l[now]), sz[now] += sz[l[now]];
    }
    if (r[now])
    {
        dfs(r[now]), sz[now] += sz[r[now]];
    }
    dp[now] = max(dp[l[now]], dp[r[now]]) + 1, sz[now] += 1;
    if (wq[l[now]] && wq[r[now]])
    {
        int sl = (dp[l[now]] <= 20 && (1 << dp[l[now]]) == sz[l[now]] + 1);
        int sr = (dp[r[now]] <= 20 && (1 << dp[r[now]]) == sz[r[now]] + 1);
        if ((sl && dp[l[now]] == dp[r[now]]) || (sr && dp[r[now]] + 1 == dp[l[now]]))
        {
            wq[now] = 1;
        }
    }
    ans += wq[now];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    wq[0] = 1, dfs(1);
    cout << ans << endl;
    return 0;
}