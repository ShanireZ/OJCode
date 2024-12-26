#include <algorithm>
#include <iostream>
using namespace std;
int dp[3005][3005], h[3005];
int main()
{
    int n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        for (int j = 1; j < n; j++) // 枚举间隔
        {
            dp[i][j] = 1; // 以第i个元素结尾 间隔为j
            if (i - j >= 1 && h[i - j] == h[i])
            {
                dp[i][j] += dp[i - j][j];
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}