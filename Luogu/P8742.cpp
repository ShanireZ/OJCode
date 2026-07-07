#include <algorithm>
#include <iostream>
using namespace std;
int dp[100005], dp2[100005], n, w, ans;
int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        for (int j = 100000 - w; j >= 0; j--)
        {
            dp2[j] = max(dp2[j], dp[j + w]);
            if (w - j >= 0)
            {
                dp2[j] = max(dp2[j], dp[w - j]);
            }
        }
        for (int j = 100000; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w]);
        }
        for (int j = 0; j <= 100000; j++)
        {
            dp[j] = max(dp[j], dp2[j]);
            dp2[j] = 0;
        }
    }
    for (int i = 1; i <= 100000; i++)
    {
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}