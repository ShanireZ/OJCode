#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int dp[205][205];
string s[205][205];
int main()
{
    int m, v, n;
    cin >> m >> v >> n;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            s[i][j] = string(n + 5, '0');
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = m; j >= a; j--)
        {
            for (int k = v; k >= b; k--)
            {
                if (dp[j][k] < dp[j - a][k - b] + c)
                {
                    dp[j][k] = dp[j - a][k - b] + c;
                    s[j][k] = s[j - a][k - b], s[j][k][i] = '1';
                }
                else if (dp[j][k] == dp[j - a][k - b] + c)
                {
                    string now = s[j - a][k - b];
                    now[i] = '1';
                    s[j][k] = max(s[j][k], now);
                }
            }
        }
    }
    cout << dp[m][v] << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (s[m][v][i] == '1')
        {
            cout << i << " ";
        }
    }
    return 0;
}
// TAG: DP 01背包 状态压缩