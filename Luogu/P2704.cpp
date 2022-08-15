#include <iostream>
using namespace std;
int dp[105][1100][1100], g[105], cnt[1100], s[1100];
int ans, n, m, pos;
int count(int x) // 统计状态x的炮兵个数
{
    int c = 0;
    while (x)
    {
        c += x % 2;
        x /= 2;
    }
    return c;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) // 读入地图,存储地图状态
    {
        int x = 0;
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            x = (ch == 'H') ? x * 2 + 1 : x * 2;
        }
        g[i] = x;
    }
    for (int i = 0; i < (1 << m); i++) // 枚举单行的所有方案,将可行方案预处理存储起来
    {
        // 对于单独的一行,这是一个可行方案,左右都无法误伤
        if (((i >> 1) & i) == 0 && ((i >> 2) & i) == 0 && ((i << 1) & i) == 0 && ((i << 2) & i) == 0)
        {
            s[++pos] = i; // 存储可行性方案及当前方案炮兵个数
            cnt[pos] = count(i);
        }
    }
    // 初始化前两行的所有状态 第0行状态为0
    // dp[a][b][c] 表示当前是第a行,第a行状态为c,第a-1行状态为b
    for (int i = 1; i <= pos; i++) // i枚举第1行状态
    {
        if (s[i] & g[1]) // 地图与方案冲突
        {
            continue;
        }
        dp[1][0][i] = cnt[i];
        ans = max(ans, cnt[i]);
        for (int j = 1; j <= pos; j++) // j枚举第二行状态
        {
            if (s[i] & s[j] || s[j] & g[2])
            {
                continue;
            }
            dp[2][i][j] = cnt[i] + cnt[j];
            ans = max(ans, cnt[i] + cnt[j]);
        }
    }
    for (int a = 3; a <= n; a++) // 枚举其他所有行
    {
        for (int i = 1; i <= pos; i++) // 枚举当前行的方案
        {
            if (s[i] & g[a])
            {
                continue;
            }
            for (int j = 1; j <= pos; j++) // 枚举上一行方案
            {
                if (s[i] & s[j] || s[j] & g[a - 1])
                {
                    continue;
                }
                for (int k = 1; k <= pos; k++) // 枚举上两行方案
                {
                    if (s[i] & s[k] || s[j] & s[k] || s[k] & g[a - 2])
                    {
                        continue;
                    }
                    dp[a][j][i] = max(dp[a][j][i], dp[a - 1][k][j] + cnt[i]);
                    ans = max(ans, dp[a][j][i]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}