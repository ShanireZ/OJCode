#include <algorithm>
#include <iostream>
using namespace std;
long long nums[15], dp[15], p10[15], cnt[15], n, ans;
int main()
{
    p10[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        p10[i] = p10[i - 1] * 10;
        dp[i] = (dp[i - 1] * 10 + p10[i - 1]);
    }
    cin >> n;
    long long sz = 0, tmp = n;
    while (tmp)
    {
        nums[++sz] = tmp % 10;
        tmp /= 10;
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
    for (int i = 1; i < 10; i++)
    {
        ans = ans + cnt[i] * i;
    }
    cout << ans << "\n";
    return 0;
}
// TAG: 递推 数位DP