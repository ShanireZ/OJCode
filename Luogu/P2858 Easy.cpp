#include <iostream>
using namespace std;
int v[2005], dp[2005][2005]; // dp[i][j] i~j范围可提供的最大价值
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        dp[i][i] = n * v[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int l = 1; l + i - 1 <= n; l++)
        {
            int r = l + i - 1;
            dp[l][r] = max(dp[l + 1][r] + v[l] * (n - i + 1), dp[l][r - 1] + v[r] * (n - i + 1));
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}