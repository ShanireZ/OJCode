#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int dp[2005], a[105][15], vis[2005], n, m;
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) // 开关1~m
    {
        for (int j = 0; j < n; j++) // 灯0~n-1
        {
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    q.push((1 << n) - 1), dp[(1 << n) - 1] = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (int i = 1; i <= m; i++)
        {
            int s = now;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1 && (s & (1 << j)) != 0) // 第k个灯时开的且a为1
                {
                    s = s ^ (1 << j);
                }
                else if (a[i][j] == -1 && (s & (1 << j)) == 0) // 第k个灯时关的且a为-1
                {
                    s = s ^ (1 << j);
                }
            }
            if (dp[s] > dp[now] + 1)
            {
                dp[s] = dp[now] + 1;
                if (!vis[s])
                {
                    q.push(s), vis[s] = 1;
                }
            }
        }
    }
    cout << (dp[0] == 0x3f3f3f3f ? -1 : dp[0]) << endl;
    return 0;
}