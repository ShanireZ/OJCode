#include <iostream>
using namespace std;
long long dp[55005];
int main()
{
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= 55000; i++)
    {
        dp[i] = 1e16;
    }
    for (int i = 1; i <= n; i++)
    {
        long long p, c;
        cin >> p >> c;
        for (int j = p; j <= 55000; j++)
        {
            dp[j] = min(dp[j], dp[j - p] + c);
        }
    }
    long long ans = 1e16;
    for (int i = h; i <= 55000; i++)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}