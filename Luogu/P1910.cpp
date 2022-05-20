#include <iostream>
using namespace std;
int dp[1005][1005];
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = m; j >= b; j--)
        {
            for (int k = x; k >= c; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - b][k - c] + a);
            }
        }
    }
    cout << dp[m][x] << endl;
    return 0;
}