#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[16005];
int dp[16005], r[16005], n, root = 1, ans = -2147483647;
void dfs(int now, int from)
{
    dp[now] = r[now];
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        dp[now] = max(dp[now], dp[now] + dp[nxt]);
    }
    ans = max(ans, dp[now]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(root, 0);
    cout << ans << endl;
    return 0;
}