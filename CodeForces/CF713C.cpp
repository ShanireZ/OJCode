#include <algorithm>
#include <iostream>
using namespace std;
long long dp[3005], a[3005], b[3005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        a[i] = b[i] = x - i;
    }
    sort(b + 1, b + 1 + n), dp[0] = 1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long long x = dp[j] + abs(a[i] - b[j]);
            dp[j] = min(dp[j - 1], x);
        }
    }
    cout << dp[n] << endl;
    return 0;
}