#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[105][105], a[105][105], pos[105], f, v, ans; // dp[x][y] 前x个花放在前y个瓶中的最大收益
int main()
{
    cin >> f >> v;
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(dp, -0x3f, sizeof(dp)), ans = -0x3f3f3f3f;
    for (int i = 1; i <= v; i++)
    {
        dp[1][i] = max(dp[1][i - 1], a[1][i]);
    }
    for (int i = 2; i <= f; i++)
    {
        for (int j = i; j <= v; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + a[i][j]);
        }
    }
    for (int i = f; i <= v; i++)
    {
        if (ans < dp[f][i])
        {
            ans = dp[f][i], pos[f] = i;
        }
    }
    cout << ans << endl;
    ans -= a[f][pos[f]];
    for (int i = f - 1; i >= 1; i--)
    {
        for (int j = i; j <= v; j++)
        {
            if (ans == dp[i][j])
            {
                pos[i] = j, ans -= a[i][j];
                break;
            }
        }
    }
    for (int i = 1; i <= f; i++)
    {
        cout << pos[i] << " ";
    }
    return 0;
}
