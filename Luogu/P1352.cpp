#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int read();
//dp[i][0]表示i不参加 dp[i][1]表示i参加
int dp[6005][2], r[6005], fa[6005];
vector<int> chs[6005];
void dfs(int now)
{
    dp[now][0] = 0;
    dp[now][1] = r[now];
    for (int i = 0; i < chs[now].size(); i++)
    {
        int nxt = chs[now][i];
        dfs(nxt);
        dp[now][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[now][1] += dp[nxt][0];
    }
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        r[i] = read();
    }
    for (int i = 1; i < n; i++)
    {
        int l = read(), k = read();
        fa[l] = k;
        chs[k].push_back(l);
    }
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == 0)
        {
            root = i;
            break;
        }
    }
    dfs(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}