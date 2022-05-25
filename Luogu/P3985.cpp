#include <algorithm>
#include <iostream>
using namespace std;
int dp[105][405], v[105], p[105];
int main()
{
    int n, w, minv = 1e9 + 3, ans = 0;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> p[i];
        minv = min(minv, v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        v[i] -= minv - 1;                 // 将价格变为1~4
        for (int j = 400; j >= v[i]; j--) // 枚举总价格
        {
            for (int k = 1; k <= 100 && j + (minv - 1) * k <= w; k++) // 枚举件数 正反无所谓 价格不能超
            {
                dp[k][j] = max(dp[k][j], dp[k - 1][j - v[i]] + p[i]);
                ans = max(ans, dp[k][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}