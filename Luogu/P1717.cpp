#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[200], t[30], f[30], d[30];
int main()
{
    int n, h;
    cin >> n >> h;
    h *= 12;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> t[i];
        t[i] += t[i - 1];
    }
    int ans = 0;
    for (int i = 1, fs = f[1]; i <= h; i++)
    {
        dp[i] = dp[i - 1] + fs;
        fs = max(0, fs - d[1]), ans = max(ans, dp[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = h; j >= t[i]; j--) // 从 i-1 -> i 空耗t[i]-t[i-1]时间
        {
            dp[j] = dp[j - (t[i] - t[i - 1])];
        }
        for (int j = h; j >= t[i] + 1; j--) // 结束时间
        {
            for (int k = 1, fs = f[i], tot = f[i]; t[i] + k <= j; k++) // 在i处钓鱼次数
            {
                dp[j] = max(dp[j], dp[j - k] + tot);
                fs = max(0, fs - d[i]);
                tot += fs;
            }
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << endl;
    return 0;
}