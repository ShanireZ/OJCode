#include <algorithm>
#include <iostream>
using namespace std;
int dp[2005], w[2005], n, m;
int main()
{
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = (dp[j] + dp[j - w[i]]) % 10;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j >= w[i])
            {
                dp[j] = (dp[j] - dp[j - w[i]] + 10) % 10;
            }
            cout << dp[j];
        }
        cout << endl;
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = (dp[j] + dp[j - w[i]]) % 10;
        }
    }
    return 0;
}