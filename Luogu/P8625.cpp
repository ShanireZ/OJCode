#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
long long n, ans, a[100005], dp[100005];
void dfs(int now, int from)
{
    dp[now] = a[now];
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        dp[now] += max(0ll, dp[nxt]);
    }
    ans = max(ans, dp[now]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}