#include <algorithm>
#include <iostream>
using namespace std;
long long dp[3], a, n, c;
int main()
{
    cin >> n >> c;
    dp[0] = 0, dp[1] = -1e18, dp[2] = -1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        long long v0 = max({dp[0], dp[1], dp[2]});
        long long v1 = max(dp[0] + a - c, dp[2] + a);
        long long v2 = dp[1];
        dp[0] = v0, dp[1] = v1, dp[2] = v2;
    }
    cout << max({dp[0], dp[1], dp[2]}) << endl;
    return 0;
}