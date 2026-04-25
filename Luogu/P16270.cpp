#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long dp[5005][5005], a[5005], b[5005], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        dp[0][i] = 0;
    }
    sort(b + 1, b + m + 1), dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= m; j++)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(a[i] - b[j]));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}