#include <algorithm>
#include <iostream>
using namespace std;
int dp[20005][2], L[20005], R[20005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> L[i] >> R[i];
    }
    // dp[x][0]停在第x行线段左端最小步数 dp[x][1]停在第x行线段右端最小步数
    dp[1][0] = R[1] - 1 + R[1] - L[1], dp[1][1] = R[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = 1 + R[i] - L[i] + min(dp[i - 1][0] + abs(R[i] - L[i - 1]), dp[i - 1][1] + abs(R[i] - R[i - 1]));
        dp[i][1] = 1 + R[i] - L[i] + min(dp[i - 1][0] + abs(L[i] - L[i - 1]), dp[i - 1][1] + abs(L[i] - R[i - 1]));
    }
    cout << min(dp[n][0] + n - L[n], dp[n][1] + n - R[n]) << endl;
    return 0;
}
// TAG: DP 线性DP