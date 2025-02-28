#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[200005];
int dp[200005][5], n, ans = -1;
void dfs(int now, int from)
{
    dp[now][0] = 1;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        for (int i = 4; i > 0; i--)
        {
            dp[now][i] = max(dp[now][i], dp[now][i - 1] + max(dp[nxt][3], dp[nxt][0]));
        }
        ans = max(ans, dp[now][4]);
        if (dp[now][1] > 4)
        {
            ans = max(ans, dp[now][1]);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    memset(dp, -0x3f, sizeof(dp));
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}