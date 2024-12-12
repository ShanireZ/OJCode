#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int val[100005], dp[100005];
vector<int> to[100005];
void dfs(int now)
{
    dp[now] = 1;
    for (int nxt : to[now])
    {
        if (dp[nxt] == 0)
        {
            dfs(nxt);
        }
        dp[now] += dp[nxt];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (val[u] > val[v])
        {
            to[u].push_back(v);
        }
        else if (val[u] < val[v])
        {
            to[v].push_back(u);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}