#include <algorithm>
#include <iostream>
using namespace std;
long long nums[15], ca[15], cb[15], dp[15], p10[15], a, b;
void makeAns(long long x, long long cnt[])
{
    long long sz = 0, tmp = x;
    while (tmp)
    {
        nums[++sz] = tmp % 10;
        tmp /= 10;
    }
    for (int i = sz; i > 0; i--)
    {
        long long now = nums[i];
        for (int j = 0; j < 10; j++)
        {
            cnt[j] += dp[i - 1] * now + p10[i - 1] * (now > j);
        }
        cnt[now] += x % p10[i - 1] + 1, cnt[0] -= p10[i - 1];
    }
}
int main()
{
    cin >> a >> b;
    p10[0] = 1;
    for (int i = 1; i <= 13; i++)
    {
        dp[i] = dp[i - 1] * 10 + p10[i - 1];
        p10[i] = p10[i - 1] * 10;
    }
    makeAns(a - 1, ca), makeAns(b, cb);
    for (int i = 0; i < 10; i++)
    {
        cout << cb[i] - ca[i] << " ";
    }
    return 0;
}
// TAG: 数位DP 递推