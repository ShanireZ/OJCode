#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, w, dp[300000][20];
int main()
{
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int pre = 0; pre < (1 << n); pre++)
        {
            int sta = ((pre >> i) << i) + pre % (1 << (i - 1)) + (1 << (i - 1));
            for (int k = 0; k <= n; k++)
            {
                if (dp[pre][k] == -1)
                {
                    continue;
                }
                if (dp[pre][k] >= c)
                {
                    dp[sta][k] = max(dp[sta][k], dp[pre][k] - c);
                }
                else
                {
                    dp[sta][k + 1] = max(dp[sta][k + 1], w - c);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (dp[(1 << n) - 1][i] != -1)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}