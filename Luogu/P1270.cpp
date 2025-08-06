#include <algorithm>
#include <iostream>
using namespace std;
int m, pos, root, dp[2005][6005], lc[2005], rc[2005];
void dfs(int &now)
{
    now = ++pos;
    int t, c;
    cin >> t >> c;
    if (c == 0) // 走廊
    {
        dfs(lc[now]), dfs(rc[now]);
        for (int i = t * 2 + 5; i <= m; i++)
        {
            for (int l = 0; l <= i - t * 2; l++)
            {
                dp[now][i] = max(dp[now][i], dp[lc[now]][l] + dp[rc[now]][i - t * 2 - l]);
            }
        }
    }
    else // 画室
    {
        for (int i = t * 2 + 5; i <= m; i++)
        {
            dp[now][i] = min(c, (i - t * 2) / 5);
        }
    }
}
int main()
{
    cin >> m;
    dfs(root);
    cout << dp[root][m - 1] << endl;
    return 0;
}