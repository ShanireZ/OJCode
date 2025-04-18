#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, c[10005], dp[10005][2];
vector<int> to[10005];
void dfs(int now, int from)
{
    dp[now][1] = c[now];
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        dp[now][0] += dp[nxt][1];
        dp[now][1] += min(dp[nxt][0], dp[nxt][1]);
    }
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
        int a, b;
        cin >> a >> b;
        to[a].emplace_back(b), to[b].emplace_back(a);
    }
    dfs(1, 0);
    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}