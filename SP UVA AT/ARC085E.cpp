#include <iostream>
using namespace std;
#define MOD 1000000007
#define MX 131077 // 2^17+5 和不超过17的后缀的最多情况数
int ok, all1, pos, noa[MX];
long long dp[45][MX], ans = 1;
int check(int now)
{
    return (now & ok) != ok;
}
int merge(int now, int x)
{
    return ((now << x) | (1 << (x - 1))) & all1;
}
int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    ok = (1 << (z - 1)) | (1 << (y + z - 1)) | (1 << (x + y + z - 1)); // ok 標準的合法後綴範本
    all1 = (1 << (x + y + z)) - 1;                                     // all1 和不超過x+y+z的全1後綴,也是後綴和的情況上限
    for (int i = 0; i <= all1; i++)
    {
        if (check(i)) // 找出所有和不超過x+y+z的不合法後綴
        {
            noa[++pos] = i;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) // 枚舉前i個數
    {
        ans = ans * 10 % MOD;
        for (int j = 1; j <= pos; j++) // 枚舉所有不合法後綴
        {
            int pre = noa[j];
            if (dp[i - 1][pre] == 0) // 剪枝->如果前i-1個數無法組成該後綴,則對後續dp沒有貢獻,所以不需要考慮後續情況
            {
                continue;
            }
            for (int k = 1; k <= 10; k++) // 枚舉前i-1個數以noa[j]為後綴時,第i個數為k的情況
            {
                int now = merge(pre, k); // noa[j]後接上k
                if (check(now))
                {
                    dp[i][now] = (dp[i][now] + dp[i - 1][pre]) % MOD;
                }
            }
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        ans = (ans + MOD - dp[n][noa[i]]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
// TAG: 狀態壓縮 DP