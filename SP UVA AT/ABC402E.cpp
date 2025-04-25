#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
double dp[500][5005], p[10], ans;
int s[10], c[10], n, x;
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> c[i] >> p[i];
        p[i] /= 100;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((j & (1 << k)) && c[k] <= i)
                {
                    dp[j][i] = max(dp[j][i], p[k] * (s[k] + dp[j ^ (1 << k)][i - c[k]]) + (1 - p[k]) * dp[j][i - c[k]]);
                    ans = max(ans, dp[j][i]);
                }
            }
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}