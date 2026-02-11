#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, dp[10005][3]; // 0自己建站 1父节点建站 2子节点建站
vector<int> es[10005];
void dfs(int now, int from)
{
    int mn = 1e6, ok = 0;
    dp[now][0] = 1;
    for (int nxt : es[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        mn = min(mn, dp[nxt][0] - dp[nxt][2]), ok += (dp[nxt][0] <= dp[nxt][2]);
        dp[now][2] += min(dp[nxt][0], dp[nxt][2]);
        dp[now][0] += min({dp[nxt][0], dp[nxt][2], dp[nxt][1]});
        dp[now][1] += min({dp[nxt][0], dp[nxt][2]});
    }
    if (ok == 0)
    {
        dp[now][2] += mn;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v), es[v].push_back(u);
    }
    dfs(1, 0);
    cout << min(dp[1][0], dp[1][2]) << endl;
    return 0;
}