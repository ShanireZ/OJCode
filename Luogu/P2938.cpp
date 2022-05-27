#include <cstring>
#include <iostream>
using namespace std;
int p[55][15], dp[500005];
int main()
{
    int s, d, m;
    cin >> s >> d >> m;
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 2; i <= d; i++)
    {
        memset(dp, 0, sizeof(dp));
        int now = 0;
        for (int j = 1; j <= s; j++)
        {
            for (int k = p[j][i - 1]; k <= m; k++)
            {
                dp[k] = max(dp[k], dp[k - p[j][i - 1]] + p[j][i] - p[j][i - 1]);
                now = max(now, dp[k]);
            }
        }
        m += now;
    }
    cout << m << endl;
    return 0;
}