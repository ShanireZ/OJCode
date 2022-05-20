#include <cmath>
#include <iostream>
using namespace std;
long long dp[25][1005];
int main()
{
    int h, k;
    cin >> h >> k;
    for (int j = 0; j <= k; j++)
    {
        dp[0][j] = j + 1;
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j] * 2;
        }
    }
    // cout << (k + 1) * pow(2, h) << endl;
    cout << dp[h][k] << endl;
    return 0;
}