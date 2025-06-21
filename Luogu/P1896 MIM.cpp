#include <algorithm>
#include <iostream>
using namespace std;
int s[520], cnt[520], pos, n, k, h1, h2;
long long dp[520][100], ans;
void dfs1(int h, int pre, int tot)
{
    if (h > h1)
    {
        dp[pre][tot]++;
        return;
    }
    for (int now = 1; now <= pos; now++)
    {
        if ((s[now] & s[pre]) || (s[now] & (s[pre] >> 1)) || (s[now] & (s[pre] << 1)))
        {
            continue;
        }
        dfs1(h + 1, now, tot + cnt[now]);
    }
}
void dfs2(int h, int pre, int tot)
{
    if (h > h2)
    {
        for (int i = 1; i <= pos; i++)
        {
            if ((s[i] & s[pre]) || (s[i] & (s[pre] >> 1)) || (s[i] & (s[pre] << 1)))
            {
                continue;
            }
            ans += dp[i][k - tot];
        }
        return;
    }
    for (int now = 1; now <= pos; now++)
    {
        if ((s[now] & s[pre]) || (s[now] & (s[pre] >> 1)) || (s[now] & (s[pre] << 1)))
        {
            continue;
        }
        dfs2(h + 1, now, tot + cnt[now]);
    }
}
int main()
{
    cin >> n >> k;
    h1 = n / 2, h2 = n - n / 2;
    for (int i = 0; i < (1 << n); i++)
    {
        if ((i & (i >> 1)) != 0)
        {
            continue;
        }
        int c = 0, now = i;
        while (now)
        {
            c += now % 2;
            now /= 2;
        }
        s[++pos] = i;
        cnt[pos] = c;
    }
    dfs1(1, 1, 0);
    dfs2(1, 1, 0);
    cout << ans << endl;
    return 0;
}