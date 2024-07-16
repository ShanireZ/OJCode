#include <algorithm>
#include <iostream>
using namespace std;
long long dp[100005][2], mod = 998244353;
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    dp[0][0] = 1;
    for (int i = 1; i <= 100000; i++)
    {
        dp[i][0] = (dp[i - 1][0] * 9 + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 1][1] * 9 + dp[i - 1][0]) % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << "9\n";
        }
        else
        {
            cout << (dp[n - 1][0] * 8 + dp[n - 1][1]) % mod << '\n';
        }
    }
    return 0;
}
// TAG: DP 动态规划