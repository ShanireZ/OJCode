#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dp[2005][2005], ans, n, m, k;
int w[2005], qz[2005], pos[2005];
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    while (k--)
    {
        for (int i = 1; i <= m; i++)
        {
            int rk;
            cin >> rk;
            pos[rk] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            w[pos[i]] = w[pos[i] + m] = q.top();
            q.pop();
        }
        for (int i = 1; i <= m * 2; i++)
        {
            qz[i] = qz[i - 1] + w[i];
        }
        for (int i = 1; i <= m * 2; i++)
        {
            for (int j = i + 1; j <= m * 2; j++)
            {
                dp[i][j] = 2147483647;
            }
        }
        for (int len = 2; len <= m; len++)
        {
            for (int l = 1; l <= m * 2; l++)
            {
                int r = l + len - 1;
                if (r > m * 2)
                {
                    continue;
                }
                for (int k = l; k < r; k++)
                {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + (qz[r] - qz[l - 1]));
                }
            }
        }
        int now = 2147483647;
        for (int i = 1; i <= m; i++)
        {
            now = min(now, dp[i][i + m - 1]);
        }
        ans += now;
        q.push(qz[m]);
    }
    cout << ans << endl;
    return 0;
}
