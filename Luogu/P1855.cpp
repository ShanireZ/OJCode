#include <iostream>
using namespace std;
int dp[205][205];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        int mi, ti;
        cin >> mi >> ti;
        for (int j = m; j >= mi; j--)
        {
            for (int k = t; k >= ti; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - mi][k - ti] + 1);
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}