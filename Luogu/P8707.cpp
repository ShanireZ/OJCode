#include <algorithm>
#include <iostream>
using namespace std;
long long dp[35][35];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        for (int j = 2; j <= m; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}