#include <algorithm>
#include <iostream>
using namespace std;
long long a, b, ca[15], cb[15], nums[15], p10[15], dp[15];
void count(long long x, long long cnt[])
{
    for (int i = 0; i < 10; i++)
    {
        cnt[i] = 0;
    }
    long long sz = 0, tmp = x;
    while (tmp)
    {
        nums[++sz] = tmp % 10;
        tmp /= 10;
    }
    for (int i = sz; i > 0; i--)
    {
        long long now = nums[i], ex = x % p10[i - 1];
        for (int j = 0; j < 10; j++)
        {
            cnt[j] += dp[i - 1] * now + p10[i - 1] * (now > j);
        }
        cnt[0] -= p10[i - 1], cnt[now] += ex + 1;
    }
}
int main()
{
    freopen("xxx.out", "w", stdout);
    p10[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        dp[i] = dp[i - 1] * 10 + p10[i - 1];
        p10[i] = p10[i - 1] * 10;
    }
    cin >> a >> b;
    while (a && b)
    {
        if (a > b)
        {
            swap(a, b);
        }
        count(a - 1, ca), count(b, cb);
        for (int i = 0; i < 10; i++)
        {
            cout << cb[i] - ca[i] << " ";
        }
        cout << "\n";
        cin >> a >> b;
    }
    return 0;
}
// TAG: 数位DP 递推