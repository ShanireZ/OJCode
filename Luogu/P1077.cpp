#include <iostream>
using namespace std;
int dp[105] = {1}, mod = 1000007, n, m, a;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = m; j >= 1; j--)
        {
            for (int k = 1; k <= min(a, j); k++)
            {
                dp[j] = (dp[j] + dp[j - k]) % mod;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}