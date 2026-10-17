#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int read();
//outd出度 dp深度 train每列火車經過的所有站台 maxdp最小高度
int outd[2005], dp[2005], train[1005][1005], maxdp;
//fa每個站台的限制條件 vis當前列車是否經過該站台
bool fa[2005][2005], vis[1005];
queue<int> q;
int main()
{
    //freopen("xxx.in", "r", stdin);
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
        for (int j = train[i][1]; j <= train[i][t]; j++) //列車範圍內每個點
        {
            //中間中轉層為n + i
            if (vis[j] == 0) //沒停
            {
                outd[n + i]++;
                fa[j][n + i] = 1;
            }
            else //停了
            {
                outd[j]++;
                fa[n + i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n + m; i++)
    {
        if (outd[i] == 0)
        {
            q.push(i);
        }
        if (i > n) //特殊情況 區間內每站都停了
        {
            dp[i] = -1;
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int j = 1; j <= n + m; j++)
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
            if (j <= n)
            {
                dp[j] = max(dp[j], dp[now] + 1);
            }
            else
            {
                dp[j] = max(dp[j], dp[now]);
            }
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