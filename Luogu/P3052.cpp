#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int v[20], dp[1000005], lst[1000005], n, w;
int main()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++) // 枚举状态
    {
        for (int j = 0; j < n; j++) // 枚举物品
        {
            if (i & (1 << j)) // 当前状态已包含第j个物品
            {
                continue;
            }
            if (lst[i] + v[j] <= w)
            {
                if (dp[i | (1 << j)] > dp[i])
                {
                    dp[i | (1 << j)] = dp[i];
                    lst[i | (1 << j)] = lst[i] + v[j];
                }
                else if (dp[i | (1 << j)] == dp[i])
                {
                    lst[i | (1 << j)] = min(lst[i | (1 << j)], lst[i] + v[j]);
                }
            }
            else
            {
                if (dp[i | (1 << j)] > dp[i] + 1)
                {
                    dp[i | (1 << j)] = dp[i] + 1;
                    lst[i | (1 << j)] = v[j];
                }
                else if (dp[i | (1 << j)] == dp[i] + 1)
                {
                    lst[i | (1 << j)] = min(lst[i | (1 << j)], v[j]);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}