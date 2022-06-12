#include <iostream>
using namespace std;
int l[1005][1005], up[1005][1005];
long long dp[1005][1005];
int main()
{
    int n, m;
    long long cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                continue;
            }
            l[i][j] = l[i][j - 1] + 1;
            up[i][j] = up[i - 1][j] + 1;
            long long x = 0;
            for (int k = i; k > i - up[i][j]; k--, x++)
            {
                if (l[k][j] < l[i][j])
                {
                    dp[i][j] += dp[k][j];
                    break;
                }
            }
            dp[i][j] += x * l[i][j];
            cnt += dp[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}