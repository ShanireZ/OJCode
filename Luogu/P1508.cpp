#include <iostream>
using namespace std;
long long eg[205][205], dp[205][205];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> eg[i][j];
            dp[i][j] = -1e18;
        }
    }
    // 初始位置在最底下的中间，也就是第m+1行的n/2+1列
    int L = n / 2 + 1, R = n / 2 + 1;
    for (int i = m; i >= 1; i--)
    {
        if (L > 1) // 每向上走一行，两侧可行范围扩大
        {
            L--, R++;
        }
        for (int j = L; j <= R; j++)
        {
            // 当前这个位置是第i行第j列，可以从底下第i+1行的j-1,j,j+1列走过来
            long long from = max(max(dp[i + 1][j - 1], dp[i + 1][j]), dp[i + 1][j + 1]);
            dp[i][j] = from + eg[i][j];
        }
    }
    long long ans = -1e18;
    for (int i = L; i <= R; i++)
    {
        ans = max(ans, dp[1][i]);
    }
    cout << ans << endl;
    return 0;
}