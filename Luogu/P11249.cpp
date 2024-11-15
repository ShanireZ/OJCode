#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a[100005], dp[100005][2], res, cnt, n;
vector<int> to[100005];
void dfs(int now, int from)
{
    dp[now][0] = dp[now][1] = 0;
    for (int nxt : to[now])
    {
        if (from == nxt)
        {
            continue;
        }
        dfs(nxt, now);
        if (dp[nxt][0] + a[nxt] > dp[now][0])
        {
            dp[now][1] = dp[now][0];
            dp[now][0] = dp[nxt][0] + a[nxt];
        }
        else if (dp[nxt][0] + a[nxt] > dp[now][1])
        {
            dp[now][1] = dp[nxt][0] + a[nxt];
        }
    }
    if (dp[now][0] + dp[now][1] + a[now] == cnt)
    {
        res = 1;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        res = cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt += a[i], to[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            to[u].emplace_back(v), to[v].emplace_back(u);
        }
        dfs(1, 0);
        cout << (res ? "Yes" : "No") << endl;
    }
    return 0;
}