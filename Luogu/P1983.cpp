#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int read();
//outd出度 dp深度 train每列火车经过的所有站点 maxdp最小高度
int outd[1005], dp[1005], train[1005][1005], maxdp;
//fa每个站点的限制条件 vis当前列车是否经过该站点
bool fa[1005][1005], vis[1005];
queue<int> q;
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        memset(vis, 0, sizeof(vis));
        int t = read();
        for (int j = 1; j <= t; j++)
        {
            train[i][j] = read();
            vis[train[i][j]] = 1;
        }
        for (int j = train[i][1]; j <= train[i][t]; j++)
        {
            if (vis[j] == 1)
            {
                continue;
            }
            for (int k = 1; k <= t; k++)
            {
                int id = train[i][k];
                if (fa[j][id] == 0)
                {
                    fa[j][id] = 1;
                    outd[id]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (outd[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (fa[now][j] == 0)
            {
                continue;
            }
            outd[j]--;
            if (outd[j] == 0)
            {
                q.push(j);
            }
            dp[j] = max(dp[j], dp[now] + 1);
            maxdp = max(maxdp, dp[j]);
        }
    }
    printf("%d\n", maxdp + 1);
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}