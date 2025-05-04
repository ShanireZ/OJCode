#include <algorithm>
#include <iostream>
using namespace std;
int t[1000005], dp[1000005][2], n, d, ans;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        t[a]++;
    }
    if (d == 0)
    {
        for (int i = 0; i <= 1000000; i++)
        {
            ans += max(t[i] - 1, 0);
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < d; i++)
    {
        dp[i][0] = t[i];
    }
    for (int i = d; i <= 1000000; i++)
    {
        dp[i][1] = dp[i - d][0];
        dp[i][0] = min(dp[i - d][0], dp[i - d][1]) + t[i];
    }
    for (int ex = 0; ex < d && 1000000 - ex >= 0; ex++)
    {
        ans += min(dp[1000000 - ex][0], dp[1000000 - ex][1]);
    }
    cout << ans << endl;
    return 0;
}