#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int coin[20], sum[100005], dp[70000], cost[70000];
int main()
{
    int k = read(), n = read(), tot = 0;
    for (int i = 1; i <= k; i++)
    {
        coin[i] = read();
        tot += coin[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = read();
        sum[i] += sum[i - 1];
    }
    int ans = 0x7f7f7f7f;
    for (int i = 1; i < int(1 << k); i++) // 枚举所有金币方案
    {
        int p = 0, status = i; // p表示状态第几位 p+1即为金币编号
        while (status)
        {
            if (status % 2 == 1)
            {
                int pre = i ^ (1 << p); // 之前的方案
                int l = dp[pre] + 1, r = n;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    (sum[mid] - sum[dp[pre]] <= coin[p + 1]) ? l = mid + 1 : r = mid - 1;
                }
                if (r > dp[i])
                {
                    dp[i] = r, cost[i] = cost[pre] + coin[p + 1];
                }
                else if (r == dp[i])
                {
                    cost[i] = min(cost[i], cost[pre] + coin[p + 1]);
                }
            }
            p++, status /= 2;
        }
        if (dp[i] == n)
        {
            ans = min(ans, cost[i]);
        }
    }
    if (ans == 0x7f7f7f7f)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", tot - ans);
    }
    return 0;
}