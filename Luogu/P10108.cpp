#include <algorithm>
#include <iostream>
using namespace std;
int a[105], b[10005], vis[10005], dp[20005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        dp[i] = -1e9;
    }
    vis[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            continue;
        }
        for (int j = 1; j <= m; j++)
        {
            int ed = i + a[j];
            dp[ed] = max(dp[ed], dp[i] + b[i]);
            vis[ed] = 1;
        }
    }
    int ans = -1e9;
    for (int i = n; i <= n * 2; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}