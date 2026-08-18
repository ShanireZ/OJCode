#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, w, c[20], dp[300005][20];
int main()
{
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int now = 0; now < (1 << n); now++)
    {
        for (int i = 0; i < n; i++)
        {
            int nxt = now | (1 << i);
            for (int t = 0; t <= n; t++)
            {
                if (dp[now][t] == -1)
                {
                    continue;
                }
                if (dp[now][t] >= c[i])
                {
                    dp[nxt][t] = max(dp[nxt][t], dp[now][t] - c[i]);
                }
                dp[nxt][t + 1] = max(dp[nxt][t + 1], w - c[i]);
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