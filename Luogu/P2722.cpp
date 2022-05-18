#include <iostream>
using namespace std;
int dp[10005];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int p, t;
        cin >> p >> t;
        for (int j = t; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - t] + p);
        }
    }
    cout << dp[m] << endl;
    return 0;
}