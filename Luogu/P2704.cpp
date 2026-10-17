#include <iostream>
using namespace std;
int dp[105][1100][1100], g[105], cnt[1100], s[1100];
int ans, n, m, pos;
int count(int x) // 統計狀態x的炮兵個數
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
    for (int i = 1; i <= n; i++) // 讀入地圖,儲存地圖狀態
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
    for (int i = 0; i < (1 << m); i++) // 枚舉單行的所有方案,將可行方案預處理儲存起來
    {
        // 對於單獨的一行,這是一個可行方案,左右都無法誤傷
        if (((i >> 1) & i) == 0 && ((i >> 2) & i) == 0 && ((i << 1) & i) == 0 && ((i << 2) & i) == 0)
        {
            s[++pos] = i; // 儲存可行性方案及當前方案炮兵個數
            cnt[pos] = count(i);
        }
    }
    // 初始化前兩行的所有狀態 第0行狀態為0
    // dp[a][b][c] 表示當前是第a行,第a行狀態為c,第a-1行狀態為b
    for (int i = 1; i <= pos; i++) // i枚舉第1行狀態
    {
        if (s[i] & g[1]) // 地圖與方案衝突
        {
            continue;
        }
        dp[1][0][i] = cnt[i];
        ans = max(ans, cnt[i]);
        for (int j = 1; j <= pos; j++) // j枚舉第二行狀態
        {
            if (s[i] & s[j] || s[j] & g[2])
            {
                continue;
            }
            dp[2][i][j] = cnt[i] + cnt[j];
            ans = max(ans, cnt[i] + cnt[j]);
        }
    }
    for (int a = 3; a <= n; a++) // 枚舉其他所有行
    {
        for (int i = 1; i <= pos; i++) // 枚舉當前行的方案
        {
            if (s[i] & g[a])
            {
                continue;
            }
            for (int j = 1; j <= pos; j++) // 枚舉上一行方案
            {
                if (s[i] & s[j] || s[j] & g[a - 1])
                {
                    continue;
                }
                for (int k = 1; k <= pos; k++) // 枚舉上兩行方案
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