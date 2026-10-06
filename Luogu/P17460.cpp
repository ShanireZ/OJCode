#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long dp[2005][2005], n, mod = 1e9;
int main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (ch == ')' && j + 1 <= i - 1)
            {
                dp[i][j] += dp[i - 1][j + 1];
            }
            if (ch == '(' && j >= 1)
            {
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}