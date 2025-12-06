#include <algorithm>
#include <iostream>
using namespace std;
long long n, ans, a[5005], dp[5005], dp2[5005], dp1[5005], mod = 998244353;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[a[i]] + dp2[a[i]]) % mod;
        for (int j = 5000; j >= 0; j--)
        {
            dp[j] = (dp[j] + dp[max(0ll, j - a[i])] + dp2[max(0ll, j - a[i])]) % mod;
        }
        for (int j = 5000; j >= 0; j--)
        {
            dp2[j] = (dp2[j] + dp1[max(0ll, j - a[i])]) % mod;
        }
        for (int j = 0; j < a[i]; j++)
        {
            dp1[j]++;
        }
    }
    cout << ans << endl;
    return 0;
}