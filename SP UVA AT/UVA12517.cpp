#include <algorithm>
#include <iostream>
using namespace std;
long long nums[15], dp[15], p10[15], ca[15], cb[15], a, b;
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
        long long now = nums[i], ex = 0;
        for (int j = 0; j < 10; j++)
        {
            cnt[j] = cnt[j] + now * dp[i - 1] + (now > j) * p10[i - 1];
        }
        for (int j = i - 1; j > 0; j--)
        {
            ex = (ex * 10 + nums[j]);
        }
        cnt[now] = (cnt[now] + ex + 1), cnt[0] = cnt[0] - p10[i - 1];
    }
}
int main()
{
    p10[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        p10[i] = p10[i - 1] * 10;
        dp[i] = (dp[i - 1] * 10 + p10[i - 1]);
    }
    cin >> a >> b;
    while (a && b)
    {
        makeAns(a - 1, ca), makeAns(b, cb);
        long long ans = 0;
        for (int i = 1; i < 10; i++)
        {
            ans = ans + (cb[i] - ca[i]) * i;
        }
        cout << ans << "\n";
        cin >> a >> b;
    }
    return 0;
}
// TAG: 递推 数位DP