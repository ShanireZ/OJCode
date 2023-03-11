#include <iostream>
using namespace std;
#define MOD 998244353
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
    ok = (1 << (z - 1)) | (1 << (y + z - 1)) | (1 << (x + y + z - 1)); // ok 标准的合法后缀模板
    all1 = (1 << (x + y + z)) - 1;                                     // all1 和不超过x+y+z的全1后缀,也是后缀和的情况上限
    for (int i = 0; i <= all1; i++)
    {
        if (check(i)) // 找出所有和不超过x+y+z的不合法后缀
        {
            noa[++pos] = i;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) // 枚举前i个数
    {
        ans = ans * 10 % MOD;
        for (int j = 1; j <= pos; j++) // 枚举所有不合法后缀
        {
            int pre = noa[j];
            if (dp[i - 1][pre] == 0) // 剪枝->如果前i-1个数无法组成该后缀,则对后续dp没有贡献,所以不需要考虑后续情况
            {
                continue;
            }
            for (int k = 1; k <= 10; k++) // 枚举前i-1个数以noa[j]为后缀时,第i个数为k的情况
            {
                int now = merge(pre, k); // noa[j]后接上k
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
// TAG: 状态压缩 DP