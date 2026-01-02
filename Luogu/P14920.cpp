#include <algorithm>
#include <iostream>
using namespace std;
long long dp[250005], n, k, ans;
int main()
{
    cin >> n >> k;
    fill(dp + 1, dp + 1 + 250000, 1e18);
    for (int i = 1; i <= n; i++)
    {
        long long a, c;
        cin >> a >> c;
        for (long long j = 250000; j >= a; j--)
        {
            dp[j] = min(dp[j], dp[j - a] + c);
            if (dp[j] <= k)
            {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}