#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, k, ans, a[1005], dp[1005][1005];
vector<int> to[1005];
void dfs(int now, int from)
{
    for (int i = a[now]; i <= k; i++)
    {
        dp[now][i] = 1; // 以now為開頭向下走,經過最多i個黑點時最多經過的總點數
    }
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        for (int j = a[now]; j <= k; j++)
        {
            ans = max(ans, dp[now][j] + dp[nxt][k - j]);
            dp[now][j] = max(dp[now][j], dp[nxt][j - a[now]] + 1);
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}