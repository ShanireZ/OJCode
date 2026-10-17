#include <iostream>
using namespace std;
int n, king, pos, s[1000], cnt[1000];
long long dp[10][1000][100]; // 第幾行 當前行狀態 當前行及之前行國王數量
int count(int x)
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
    cin >> n >> king;
    for (int i = 1; i < (1 << n); i++) // 枚舉一行的所有狀態
    {
        if (i & (i << 1)) // 當前狀態有國王相鄰
        {
            continue;
        }
        s[++pos] = i;        // 可行狀態
        cnt[pos] = count(i); // 當前狀態的國王數量
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) // 枚舉行
    {
        for (int j = 0; j <= pos; j++) // 枚舉當前行的狀態
        {
            for (int k = 0; k <= pos; k++) // 枚舉上一行的狀態
            {
                if ((s[j] & s[k]) || (s[j] & (s[k] << 1)) || (s[j] & (s[k] >> 1))) // 狀態j和k有衝突
                {
                    continue;
                }
                for (int x = cnt[j]; x <= king; x++) // 枚舉到當前行為止的國王總數量
                {
                    dp[i][j][x] += dp[i - 1][k][x - cnt[j]];
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= pos; i++)
    {
        ans = ans + dp[n][i][king];
    }
    cout << ans << endl;
    return 0;
}