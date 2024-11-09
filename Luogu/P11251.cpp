#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, ans, c[100005], dp[100005];
void dfs(int now, int from)
{
    int zc = 0, cc = 0;
    for (int i = 0; i < (int)to[now].size(); i++)
    {
        int nxt = to[now][i];
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        if (c[now] != c[nxt])
        {
            if (dp[nxt] >= zc)
            {
                cc = zc;
                zc = dp[nxt];
            }
            else if (dp[nxt] > cc)
            {
                cc = dp[nxt];
            }
        }
    }
    dp[now] = zc + 1, ans = max(ans, zc + cc + 1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v);
        to[v].emplace_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}