#include <iostream>
using namespace std;
long long dp1[20], dp2[20];
int main()
{
    int n, m;
    cin >> n >> m;
    dp1[0] = -1, dp2[0] = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        dp1[0] = max(dp1[0], x), dp2[0] = min(dp2[0], x);
    }
    for (int i = 1; i <= m; i++)
    {
        dp1[i] = max(dp1[i - 1] + 2, dp1[i - 1] * 2), dp2[i] = min(dp2[i - 1] - 2, dp2[i - 1] / 2);
    }
    long long ans = 0;
    for (int i = 0; i <= m; i++)
    {
        ans = max(ans, dp1[i] - dp2[m - i]);
    }
    cout << ans << endl;
    return 0;
}