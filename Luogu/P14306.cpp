#include <algorithm>
#include <iostream>
using namespace std;
long long a[100005], dp[100005], n, c, T, k, ans;
int main()
{
    cin >> c >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1), dp[1] = ans = k;
        for (int i = 2; i <= n; i++)
        {
            long long ex = k - (a[i] - a[i - 1]);
            dp[i] = max(dp[i - 1], k) + ex;
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}