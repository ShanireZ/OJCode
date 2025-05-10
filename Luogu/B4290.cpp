#include <algorithm>
#include <iostream>
using namespace std;
int n, g, tot, ans, dp[2005], a[2005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        i == 1 ? g = a[i] : g = __gcd(g, a[i]);
        tot += a[i];
    }
    if (g != 1)
    {
        cout << -1 << endl;
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i < tot; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= a[j])
            {
                dp[i] = max(dp[i], dp[i - a[j]]);
            }
        }
        ans += (dp[i] == 0);
    }
    cout << ans << endl;
    return 0;
}