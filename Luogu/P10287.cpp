#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> to[100005];
int n, m, ans, a[100005], dg[100005], dp[100005][15];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][a[i]] = 1; // 截止到点i且以a[i]结尾的最长序列的长度
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), dg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dg[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : to[now])
        {
            for (int i = 1; i <= 10; i++)
            {
                dp[nxt][i] = max(dp[nxt][i], dp[now][i]);
                if (a[nxt] >= i)
                {
                    dp[nxt][a[nxt]] = max(dp[nxt][a[nxt]], dp[now][i] + 1);
                }
            }
            dg[nxt]--;
            if (dg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
        for (int i = 1; i <= 10; i++)
        {
            ans = max(ans, dp[now][i]);
        }
    }
    cout << ans << endl;
    return 0;
}