#include <iostream>
using namespace std;
int n, king, pos, s[1000], cnt[1000];
long long dp[10][1000][100]; // 第几行 当前行状态 当前行及之前行国王数量
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
    for (int i = 1; i < (1 << n); i++) // 枚举一行的所有状态
    {
        if (i & (i << 1)) // 当前状态有国王相邻
        {
            continue;
        }
        s[++pos] = i;        // 可行状态
        cnt[pos] = count(i); // 当前状态的国王数量
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) // 枚举行
    {
        for (int j = 0; j <= pos; j++) // 枚举当前行的状态
        {
            for (int k = 0; k <= pos; k++) // 枚举上一行的状态
            {
                if ((s[j] & s[k]) || (s[j] & (s[k] << 1)) || (s[j] & (s[k] >> 1))) // 状态j和k有冲突
                {
                    continue;
                }
                for (int x = cnt[j]; x <= king; x++) // 枚举到当前行为止的国王总数量
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