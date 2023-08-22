#include <algorithm>
#include <iostream>
using namespace std;
long long nums[25], dp[25], p10[25], ca[15], cb[15], mod;
void makeAns(long long x, long long cnt[])
{
    long long sz = 0, tmp = x;
    while (tmp)
    {
        nums[++sz] = tmp % 10;
        tmp /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cnt[i] = 0;
    }
    for (int i = sz; i > 0; i--)
    {
        long long now = nums[i];
        for (int j = 0; j < 10; j++)
        {
            cnt[j] = (cnt[j] + now * dp[i - 1] % mod + (now > j) * p10[i - 1] % mod) % mod;
        }
        long long ex = 0;
        for (int j = i - 1; j > 0; j--)
        {
            ex = (ex * 10 + nums[j]) % mod;
        }
        cnt[now] = (cnt[now] + ex + 1) % mod;
        cnt[0] = (cnt[0] - p10[i - 1] + mod) % mod;
    }
}
int main()
{
    long long t;
    cin >> t;
    p10[0] = 1, mod = 1e9 + 7;
    for (int i = 1; i <= 19; i++)
    {
        p10[i] = p10[i - 1] * 10 % mod;
        dp[i] = (dp[i - 1] * 10 + p10[i - 1]) % mod;
    }
    while (t--)
    {
        long long a, b, ans = 0;
        cin >> a >> b;
        makeAns(a - 1, ca), makeAns(b, cb);
        for (int i = 1; i < 10; i++)
        {
            ans = (ans + (cb[i] - ca[i] + mod) * i % mod) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
// TAG: 递推 数位DP