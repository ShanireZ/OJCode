#include <algorithm>
#include <iostream>
using namespace std;
int n, ans = 1e9, dp[5000005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 5000000; j >= 0; j--)
        {
            dp[j] = dp[j] + b;
            if (j >= a)
            {
                dp[j] = min(dp[j], dp[j - a]);
            }
        }
    }
    for (int i = 0; i <= 5000000; i++)
    {
        ans = min(ans, max(i, dp[i]));
    }
    cout << ans << endl;
    return 0;
}