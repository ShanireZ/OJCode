#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> to[3005];
int dp[3005][3005], p[3005], sz[3005], n, m;
void dfs(int now)
{
    dp[now][0] = 0;
    for (Edge e : to[now])
    {
        int nxt = e.v, w = e.w;
        dfs(nxt);
        sz[now] += sz[nxt];
        for (int i = sz[now]; i >= 1; i--)
        {
            for (int j = 1; j <= sz[nxt]; j++)
            {
                dp[now][i] = max(dp[now][i], dp[now][i - j] + dp[nxt][j] - w);
            }
        }
    }
}
int main()
{
    memset(dp, -0x3f, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int v, w;
            cin >> v >> w;
            to[i].push_back(Edge{v, w});
        }
    }
    for (int i = n - m + 1; i <= n; i++)
    {
        cin >> p[i];
        dp[i][1] = p[i], sz[i] = 1;
    }
    dfs(1);
    for (int i = m; i >= 0; i--)
    {
        if (dp[1][i] >= 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}